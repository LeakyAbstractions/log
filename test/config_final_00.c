
# include "testing.h"


/**
 * Test config finalization (null config)
 */
TEST_CASE{

    bool result;

    result = log_config_finalize(NULL);

    TEST_ASSERT(!result);
}
