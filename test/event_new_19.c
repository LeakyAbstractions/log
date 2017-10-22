
# include "testing.h"

static bool append(struct log_appender * appender, struct log_layout * layout, struct log_logger * logger, struct log_event * event);
static struct log_appender_type test_appender_type = { NULL, NULL, append };
static struct log_appender test_appender = { "test", &test_appender_type, NULL, true, false };
static int format(struct log_layout * layout, struct fmt_stream * stream, struct log_logger * logger, struct log_event * event);
static struct log_layout_type test_layout_type = { NULL, NULL, format };
static struct log_layout test_layout = { "test", &test_layout_type, NULL, true, false };
static struct log_logger test_logger = { "test", &test_appender, &test_layout, 0, 20, true, false };
static struct log_logger * test_list[] = { &test_logger, NULL };
struct log_context test_context = { "test_module", test_list, NULL, NULL, 10, 0 };
struct fmt_stream test_stream = { 0 };

/**
 * Test logger list initialization/finalization with a valid logger (no layout)
 */
TEST_CASE{

    char buffer[512];

    fmt_stream_buffer(&test_stream, buffer, sizeof(buffer));

    log_event_new(&test_context, 30, "test_function", "test_file", 123, NULL, "Dummy %s %d", "event", 1);
    log_event_new(&test_context, 20, "test_function", "test_file", 123, NULL, "Dummy %s %d", "event", 2);
    log_event_new(&test_context, 15, "test_function", "test_file", 123, NULL, "Dummy %s %d", "event", 3);
    log_event_new(&test_context, 10, "test_function", "test_file", 123, NULL, "Dummy %s %d", "event", 4);
    log_event_new(&test_context, LOG_LEVEL_MIN, "test_function", "test_file", 123, NULL, "Dummy %s %d", "event", 5);

    TEST_EQUALS("(TEST Dummy event 1 TEST)(TEST Dummy event 2 TEST)", buffer);

    TEST_ASSERT(test_logger.sequence == 2);
}

static int format(struct log_layout * layout, struct fmt_stream * stream, struct log_logger * logger, struct log_event * event){

    (void)layout;
    (void)stream;
    (void)logger;
    (void)event;

    return( fmt_print(stream, "(TEST %{*} TEST)", event->format, event->arg) );
}

static bool append(struct log_appender * appender, struct log_layout * layout, struct log_logger * logger, struct log_event * event){

    (void)appender;

    return( layout->type->format(layout, &test_stream, logger, event) );
}
