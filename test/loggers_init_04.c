
# include "testing.h"

static struct log_logger test_logger = { "test", NULL, NULL, 0, 100, false, false };
static struct log_logger * test_list[] = { &test_logger, NULL };


/**
 * Test logger list initialization (logger w/o appender and w/o layout)
 */
TEST_CASE{

    bool result;

    result = log_loggers_initialize(test_list);
    TEST_ASSERT(!result);
    TEST_ASSERT(!test_logger.is_initialized);
}
