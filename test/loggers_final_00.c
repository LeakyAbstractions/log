
# include "testing.h"


/**
 * Test logger list finalization (null list)
 */
TEST_CASE{

    bool result;

    result = log_loggers_finalize(NULL);
    TEST_ASSERT(!result);
}
