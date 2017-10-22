
# include "testing.h"

static bool appended = false;
static int format(struct log_layout * layout, struct fmt_stream * stream, struct log_logger * logger, struct log_event * event);
static bool append(struct log_appender * appender, struct log_layout * layout, struct log_logger * logger, struct log_event * event);
static struct log_layout_type test_layout_type = { NULL, NULL, format };
static struct log_appender_type test_appender_type = { NULL, NULL, append };
static struct log_layout test_layout = { "test", &test_layout_type, NULL, true, false };
static struct log_appender test_appender = { "test", &test_appender_type, NULL, true, false };
static struct log_logger test_logger = { "test", &test_appender, &test_layout, 0, LOG_LEVEL_MIN, true, false };
static struct log_logger * test_list[] = { &test_logger, NULL };
struct log_context test_context = { "test_module", test_list, NULL, NULL, LOG_LEVEL_MIN, false };
int error_object = 123;


/**
 * Test event (logger w/ appender and formatter)
 */
TEST_CASE{

    log_event_new(&test_context, LOG_LEVEL_MIN, "test_function", "test_file", 123, &error_object, "Dummy event");

    TEST_ASSERT(test_logger.sequence == 1);
    TEST_ASSERT(appended);
}

static bool append(struct log_appender * appender, struct log_layout * layout, struct log_logger * logger, struct log_event * event){

    int result;

    TEST_ASSERT(appender == &test_appender);
    TEST_ASSERT(layout);
    TEST_ASSERT(logger == &test_logger);
    TEST_ASSERT(event->level == LOG_LEVEL_MIN);
    TEST_EQUALS("test_module", event->module);
    TEST_EQUALS("test_function", event->function);
    TEST_EQUALS("test_file", event->file);
    TEST_ASSERT(event->line == 123);
    TEST_ASSERT(event->error_object == &error_object);
    TEST_EQUALS("Dummy event", event->format);

    appended = true;

    result = layout->type->format(layout, NULL, logger, event);

    TEST_ASSERT(result == 321);

    return(true);
}

static int format(struct log_layout * layout, struct fmt_stream * stream, struct log_logger * logger, struct log_event * event){

    TEST_ASSERT(layout == &test_layout);
    TEST_ASSERT(!stream);
    TEST_ASSERT(logger == &test_logger);
    TEST_ASSERT(event->level == LOG_LEVEL_MIN);
    TEST_EQUALS("test_module", event->module);
    TEST_EQUALS("test_function", event->function);
    TEST_EQUALS("test_file", event->file);
    TEST_ASSERT(event->line == 123);
    TEST_ASSERT(event->error_object == &error_object);
    TEST_EQUALS("Dummy event", event->format);

    return(321);
}
