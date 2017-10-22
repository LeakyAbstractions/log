
# include "testing.h"


/**
 * Test config initialization (null config)
 */
TEST_CASE{

    bool result;

    result = log_config_initialize(NULL);

    TEST_ASSERT(!result);
}
