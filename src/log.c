/**
 *
 * @file        log.c
 *
 * log source code file
 *
 * @version     1.0.0
 * @author      Copyright (c) 2017 Guillermo Calvo
 *
 */

# include <errno.h>
# include <stdarg.h>
# include <stdio.h>
# include <assert.h>
# include "log.h"

# ifdef NDEBUG
#   define DIAGNOSE(MESSAGE, ID)
# else
#   define DIAGNOSE(MESSAGE, ID) fprintf(stderr, MESSAGE ".\n", ID)
# endif

bool log_config_initialize(struct log_config * config){

    if(!config || config->is_initialized){
        return(false);
    }

    config->is_initialized = config->type && ( !config->type->initialize || config->type->initialize(config) );
    if(!config->is_initialized){
        DIAGNOSE("Configuration: %s was not properly initialized", config->id);
    }

    return(config->is_initialized);
}

bool log_config_finalize(struct log_config * config){

    if(!config || !config->is_initialized || config->is_finalized){
        return(false);
    }

    config->is_finalized = config->type && ( !config->type->finalize || config->type->finalize(config) );
    if(!config->is_finalized){
        DIAGNOSE("Configuration: %s was not properly finalized", config->id);
    }

    return(config->is_finalized);
}

bool log_loggers_initialize(struct log_logger * * loggers){

    int errors = 0;
    struct log_logger * logger;

    if(!loggers){
        return(false);
    }

    for(; (logger = *loggers); loggers++){

        if(!logger->is_initialized && logger->level < LOG_LEVEL_MAX){

            struct log_appender * appender = logger->appender;
            struct log_layout * layout = logger->layout;

            if(appender && !appender->is_initialized){

                struct log_appender_type * type = appender->type;

                appender->is_initialized = type && type->append && (!type->initialize || type->initialize(appender));
                if(!appender->is_initialized){
                    DIAGNOSE("Appender: %s was not properly initialized", appender->id);
                }
            }

            if(layout && !layout->is_initialized){

                struct log_layout_type * type = layout->type;

                layout->is_initialized = type && type->format && ( !type->initialize || type->initialize(layout) );
                if(!layout->is_initialized){
                    DIAGNOSE("Layout: %s was not properly initialized", layout->id);
                }
            }

            logger->is_initialized = (appender && appender->is_initialized && (!layout || layout->is_initialized));
            if(!logger->is_initialized){
                DIAGNOSE("Logger: %s was not properly initialized", logger->id);
                errors++;
            }
        }
    }

    return(errors == 0);
}

bool log_loggers_finalize(struct log_logger * * loggers){

    int errors = 0;
    struct log_logger * logger;

    if(!loggers){
        return(false);
    }

    for(; (logger = *loggers); loggers++){

        if(logger->is_initialized && !logger->is_finalized){

            struct log_appender * appender = logger->appender;
            struct log_layout * layout = logger->layout;

            if(appender && appender->is_initialized && !appender->is_finalized){

                struct log_appender_type * type = appender->type;

                appender->is_finalized = type && ( !type->finalize || type->finalize(appender) );
                if(!appender->is_finalized){
                    DIAGNOSE("Appender: %s was not properly finalized", appender->id);
                }
            }

            if(layout && layout->is_initialized && !layout->is_finalized){

                struct log_layout_type * type = layout->type;

                layout->is_finalized = type && ( !type->finalize || type->finalize(layout) );
                if(!layout->is_finalized){
                    DIAGNOSE("Layout: %s was not properly finalized", layout->id);
                }
            }

            logger->is_finalized = ( (!appender || appender->is_finalized) && (!layout || layout->is_finalized) );
            if(!logger->is_finalized){
                DIAGNOSE("Logger: %s was not properly finalized", logger->id);
                errors++;
            }
        }
    }

    return(errors == 0);
}

void log_event_new(struct log_context * context,
  int level, const char * function, const char * file, int line, const void * error_object, const char * format, ...){

    int                 error_number = errno;
    int                 iteration = 0;
    bool                appended  = false;
    bool                ready     = true;
    bool                finished  = false;
    struct log_event    event     = {0};
    struct log_config * config;
    va_list             arg;

    if(!context){
        return;
    }

    config = context->configuration;
    if(config){
        if(!config->is_initialized || config->is_finalized || !config->type || !config->type->configure){
            config = NULL;
            if(!context->has_errors){
                DIAGNOSE("Module: %s is not properly configured", context->module);
                context->has_errors = true;
            }
        }else{
            ready = config->type->configure(context, &finished, 0);
        }
    }

    if( (!ready || !context->loggers) && !context->has_errors ){
        return;
    }

    event.level         = level;
    event.module        = context->module;
    event.function      = function;
    event.file          = file;
    event.line          = line;
    event.format        = format;
    event.arg           = &arg;
    event.error_number  = error_number;
    event.error_object  = error_object;
    (void)timespec_get(&event.timestamp, TIME_UTC);

    while(ready && context->loggers){

        struct log_logger * * list = context->loggers;
        struct log_logger * logger;

        for(; (logger = *list) && logger->is_initialized && !logger->is_finalized && logger->level <= level; list++){

            struct log_appender * appender = logger->appender;

            if(appender && appender->is_initialized && !appender->is_finalized){

                struct log_layout * layout = logger->layout;

                if(!layout || !layout->is_initialized || layout->is_finalized){
                    layout = NULL;
                }

                assert(appender->type && appender->type->append);
                assert(!layout || (layout->type && layout->type->format));
                va_start(arg, format);

                if( appender->type->append(appender, layout, logger, &event) ){
                    logger->sequence++;
                    appended = true;
                }

                va_end(arg);
            }
        }

        ready = !finished && config && config->type->configure(context, &finished, ++iteration);
    }

    if(!appended){

        struct fmt_stream out = {0};

        fmt_stream_file(&out, stdout);
        va_start(arg, format);
        (void)fmt_print(&out, "%{*}\n", format, &arg);
        va_end(arg);
    }
}
