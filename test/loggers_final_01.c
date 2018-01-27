
# include "testing.h"

static struct log_logger * empty_list[] = { NULL };


/**
 * Test logger list finalization (empty list)
 */
TEST_CASE{

    bool result;

    result = log_loggers_finalize(empty_list);
    TEST_ASSERT(result);
}
