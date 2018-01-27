/**
 *
 * @file        log.h
 *
 * log header file
 *
 * @version     1.0.0
 * @author      Copyright (c) 2017 Guillermo Calvo
 *
 */

# ifndef LOG_H
# define LOG_H

# include <time.h>
# include <stdbool.h>
# include <fmt.h>

/** Minimum logging level (inhibiting logging at this level effectively turns on all logging) */
# ifndef LOG_LEVEL_MIN
#   define LOG_LEVEL_MIN 0
# endif

/** Minimum logging level (inhibiting logging at this level effectively turns off logging) */
# ifndef LOG_LEVEL_MAX
#   define LOG_LEVEL_MAX 255
# endif

/** Compile-time logging level (events with greater logging level will be *statically* inhibited) */
# ifndef LOG_LEVEL
#   define LOG_LEVEL LOG_LEVEL_MAX
# endif

/** Expression that will be evaluated and used as the current logging context */
# ifndef LOG_CONTEXT
#   define LOG_CONTEXT &logging_context
# endif

/** Expression that will be evaluated and used as the current error object for logging events */
# ifndef LOG_ERROR_OBJECT
#   define LOG_ERROR_OBJECT NULL
# endif

/** Expression that will be evaluated and used as the current function name for logging events */
# ifndef LOG_FUNCTION
#   define LOG_FUNCTION __func__
# endif

/** Creates an appender of the specified type with static visibility */
# define LOG_APPENDER(ID, TYPE) \
    static struct TYPE##_config ID##_configuration; \
    static struct log_appender ID = { #ID, &TYPE, &ID##_configuration, false, false }; \
    static struct TYPE##_config ID##_configuration

/** Creates a layout of the specified type with static visibility */
# define LOG_LAYOUT(ID, TYPE) \
    static struct TYPE##_config ID##_configuration; \
    static struct log_layout ID = { #ID, &TYPE, &ID##_configuration, false, false }; \
    static struct TYPE##_config ID##_configuration

/** Creates a logger */
# define LOG_LOGGER(ID, LEVEL, APPENDER, LAYOUT) \
    struct log_logger ID = { #ID, &APPENDER, &LAYOUT, 0, LEVEL, false, false }

/** Determines if a specific log level is inhibited at compile-time or due to current logging context */
# define LOG_IS_LEVEL_DISABLED(LEVEL) \
    ( (LEVEL) > LOG_LEVEL || (LEVEL) > (LOG_CONTEXT)->level )

/** Generates a new logging event */
# define LOG_EVENT(LEVEL, MESSAGE) ( LOG_IS_LEVEL_DISABLED(LEVEL) ? (void)0 : \
    log_event_new((LOG_CONTEXT), LEVEL, (LOG_FUNCTION), __FILE__, __LINE__, (LOG_ERROR_OBJECT), MESSAGE) )

/** Represents a logging event */
struct log_event{
    int                         level;
    struct timespec             timestamp;
    const char *                module;
    const char *                function;
    const char *                file;
    int                         line;
    const char *                format;
    va_list *                   arg;
    int                         error_number;
    const void *                error_object;
};

/** Dispatches logging events through its appender */
struct log_logger{
    const char *                id;
    struct log_appender *       appender;
    struct log_layout *         layout;
    size_t                      sequence;
    int                         level;
    bool                        is_initialized;
    bool                        is_finalized;
};

/** Represents the logging context of a specific source file */
struct log_context{
    const char *                module;
    struct log_logger * *       loggers;
    struct log_config *         configuration;
    void *                      data;
    int                         level;
    bool                        has_errors;
};

/** Represents the configuration of a logging context */
struct log_config{
    const char *                id;
    struct log_config_type *    type;
    void *                      data;
    bool                        is_initialized;
    bool                        is_finalized;
};

/** Represents a type of logging configurations */
struct log_config_type{
    bool                        (*initialize)(struct log_config * config);
    bool                        (*finalize)(struct log_config * config);
    bool                        (*configure)(struct log_context * context, bool * finished, int iteration);
};

/** Transforms logging events and outputs them to a specific stream */
struct log_layout{
    const char *                id;
    struct log_layout_type *    type;
    void *                      configuration;
    bool                        is_initialized;
    bool                        is_finalized;
};

/** Represents a type of layouts */
struct log_layout_type{
    bool                        (*initialize)(struct log_layout * layout);
    bool                        (*finalize)(struct log_layout * layout);
    int                         (*format)(struct log_layout * layout,
                                  struct fmt_stream * stream, struct log_logger * logger, struct log_event * event);
};

/** Delivers logging events and outputs them to their destination */
struct log_appender{
    const char *                id;
    struct log_appender_type *  type;
    void *                      configuration;
    bool                        is_initialized;
    bool                        is_finalized;
};

/** Represents a type of appenders */
struct log_appender_type{
    bool                        (*initialize)(struct log_appender * appender);
    bool                        (*finalize)(struct log_appender * appender);
    bool                        (*append)(struct log_appender * appender,
                                  struct log_layout * layout, struct log_logger * logger, struct log_event * event);
};

/** Creates a new logging event and delivers it to the loggers configured in the current logging context */
extern void log_event_new(struct log_context * context,
  int level, const char * function, const char * file, int line, const void * error_object, const char * format, ...);

/** Initializes the specified logging configuration */
extern bool log_config_initialize(struct log_config * config);

/** Finalizes the specified logging configuration */
extern bool log_config_finalize(struct log_config * config);

/** Initializes a list of loggers */
extern bool log_loggers_initialize(struct log_logger * * loggers);

/** Finalizes a list of loggers */
extern bool log_loggers_finalize(struct log_logger * * loggers);

# endif
