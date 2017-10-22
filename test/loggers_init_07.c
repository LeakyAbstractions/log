
# include "testing.h"

static struct log_layout_type test_layout_type = { NULL, NULL, NULL };
static struct log_appender_type test_appender_type = { NULL, NULL, NULL };
static struct log_layout test_layout = { "test", &test_layout_type, NULL, false, false };
static struct log_appender test_appender = { "test", &test_appender_type, NULL, false, false };
static struct log_logger test_logger = { "test", &test_appender, &test_layout, 0, 100, false, false };
static struct log_logger * test_list[] = { &test_logger, NULL };


/**
 * Test logger list initialization (logger w/ appender and layout w/ types w/o any functions)
 */
TEST_CASE{

    bool result;

    result = log_loggers_initialize(test_list);
    TEST_ASSERT(!result);
    TEST_ASSERT(!test_logger.is_initialized);
    TEST_ASSERT(!test_appender.is_initialized);
    TEST_ASSERT(!test_layout.is_initialized);
}
