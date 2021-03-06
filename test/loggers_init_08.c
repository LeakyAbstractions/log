
# include "testing.h"

static int format(struct log_layout * layout, struct fmt_stream * stream, struct log_logger * logger, struct log_event * event);
static bool append(struct log_appender * appender, struct log_layout * layout, struct log_logger * logger, struct log_event * event);
static struct log_layout_type test_layout_type = { NULL, NULL, format };
static struct log_appender_type test_appender_type = { NULL, NULL, append };
static struct log_layout test_layout = { "test", &test_layout_type, NULL, false, false };
static struct log_appender test_appender = { "test", &test_appender_type, NULL, false, false };
static struct log_logger test_logger = { "test", &test_appender, &test_layout, 0, 100, false, false };
static struct log_logger * test_list[] = { &test_logger, NULL };


/**
 * Test logger list initialization (logger w/ appender and layout w/ types w action functions BUT w/o initialize functions)
 */
TEST_CASE{

    bool result;

    result = log_loggers_initialize(test_list);
    TEST_ASSERT(result);
    TEST_ASSERT(test_logger.is_initialized);
    TEST_ASSERT(test_appender.is_initialized);
    TEST_ASSERT(test_layout.is_initialized);
}

static int format(struct log_layout * layout, struct fmt_stream * stream, struct log_logger * logger, struct log_event * event){

    (void)layout;
    (void)stream;
    (void)logger;
    (void)event;

    return(0);
}

static bool append(struct log_appender * appender, struct log_layout * layout, struct log_logger * logger, struct log_event * event){

    (void)appender;
    (void)layout;
    (void)logger;
    (void)event;

    return(false);
}
