
# include "testing.h"

static struct log_config test_config = { "test", NULL, NULL, false, false };


/**
 * Test config finalization (config not initialized)
 */
TEST_CASE{

    bool result;

    result = log_config_finalize(&test_config);

    TEST_ASSERT(!result);
}
