
# include "testing.h"

static bool append(struct log_appender * appender, struct log_layout * layout, struct log_logger * logger, struct log_event * event);
static bool initialize_appender(struct log_appender * appender);
static struct log_appender_type test_appender_type = { initialize_appender, NULL, append };
static struct log_appender test_appender = { "test", &test_appender_type, NULL, false, false };
static struct log_logger test_logger = { "test", &test_appender, NULL, 0, 100, false, false };
static struct log_logger * test_list[] = { &test_logger, NULL };


/**
 * Test logger list initialization (logger w/ appender but no layout)
 */
TEST_CASE{

    bool result;

    result = log_loggers_initialize(test_list);
    TEST_ASSERT(result);
    TEST_ASSERT(test_logger.is_initialized);
    TEST_ASSERT(test_appender.is_initialized);
}

static bool initialize_appender(struct log_appender * appender){

    (void)appender;

    return(true);
}

static bool append(struct log_appender * appender, struct log_layout * layout, struct log_logger * logger, struct log_event * event){

    (void)appender;
    (void)layout;
    (void)logger;
    (void)event;

    return(false);
}
