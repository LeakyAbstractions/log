
# include "testing.h"

static struct log_layout_type test_layout_type = { NULL, NULL, NULL };
static struct log_appender_type test_appender_type = { NULL, NULL, NULL };
static struct log_layout test_layout = { "test", &test_layout_type, NULL, true, false };
static struct log_appender test_appender = { "test", &test_appender_type, NULL, true, false };
static struct log_logger test_logger = { "test", &test_appender, &test_layout, 0, 100, true, false };
static struct log_logger * test_list[] = { &test_logger, NULL };


/**
 * Test logger list finalization (logger w/ appender and layout /w type w/o finalize functions)
 */
TEST_CASE{

    bool result;

    result = log_loggers_finalize(test_list);
    TEST_ASSERT(result);
    TEST_ASSERT(test_logger.is_finalized);
    TEST_ASSERT(test_appender.is_finalized);
    TEST_ASSERT(test_layout.is_finalized);
}
