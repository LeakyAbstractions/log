
# include "testing.h"

static struct log_logger * empty_list[] = { NULL };


/**
 * Test logger list initialization (empty list)
 */
TEST_CASE{

    bool result;

    result = log_loggers_initialize(empty_list);
    TEST_ASSERT(result);
}
