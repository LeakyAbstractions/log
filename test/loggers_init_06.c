
# include "testing.h"

static struct log_layout test_layout = { "test", NULL, NULL, false, false };
static struct log_appender test_appender = { "test", NULL, NULL, false, false };
static struct log_logger test_logger = { "test", &test_appender, &test_layout, 0, 100, false, false };
static struct log_logger * test_list[] = { &test_logger, NULL };


/**
 * Test logger list initialization (logger w/ typeless appender and layout)
 */
TEST_CASE{

    bool result;

    result = log_loggers_initialize(test_list);
    TEST_ASSERT(!result);
    TEST_ASSERT(!test_logger.is_initialized);
    TEST_ASSERT(!test_appender.is_initialized);
    TEST_ASSERT(!test_layout.is_initialized);
}
