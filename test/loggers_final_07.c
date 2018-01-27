
# include "testing.h"

static struct log_layout test_layout = { "test", NULL, NULL, true, false };
static struct log_appender test_appender = { "test", NULL, NULL, true, false };
static struct log_logger test_logger = { "test", &test_appender, &test_layout, 0, 100, true, false };
static struct log_logger * test_list[] = { &test_logger, NULL };


/**
 * Test logger list finalization (logger w/ typeless appender and layout)
 */
TEST_CASE{

    bool result;

    result = log_loggers_finalize(test_list);
    TEST_ASSERT(!result);
    TEST_ASSERT(!test_logger.is_finalized);
    TEST_ASSERT(!test_appender.is_finalized);
    TEST_ASSERT(!test_layout.is_finalized);
}
