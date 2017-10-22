
# include "testing.h"

static bool appended = false;
static bool append(struct log_appender * appender, struct log_layout * layout, struct log_logger * logger, struct log_event * event);
static struct log_appender_type test_appender_type = { NULL, NULL, append };
static struct log_appender test_appender = { "test", &test_appender_type, NULL, true, false };
static struct log_logger test_logger = { "test", &test_appender, NULL, 0, LOG_LEVEL_MIN, true, false };
static struct log_logger * test_list[] = { &test_logger, NULL };
struct log_context test_context = { "test_module", test_list, NULL, NULL, LOG_LEVEL_MIN, false };
int error_object = 123;


/**
 * Test event (logger w/ appender)
 */
TEST_CASE{

    log_event_new(&test_context, LOG_LEVEL_MIN, "test_function", "test_file", 123, &error_object, "Dummy event");

    TEST_ASSERT(test_logger.sequence == 1);
    TEST_ASSERT(appended);
}

static bool append(struct log_appender * appender, struct log_layout * layout, struct log_logger * logger, struct log_event * event){

    (void)appender;
    (void)layout;
    (void)logger;
    (void)event;

    appended = true;

    return(true);
}
