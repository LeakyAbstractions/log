
# include "testing.h"


/**
 * Test logger list initialization (null list)
 */
TEST_CASE{

    bool result;

    result = log_loggers_initialize(NULL);
    TEST_ASSERT(!result);
}
