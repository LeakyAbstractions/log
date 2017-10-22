
# include "testing.h"

static struct log_config test_config = { "test", NULL, NULL, true, true };


/**
 * Test config finalization (config already finalized)
 */
TEST_CASE{

    bool result;

    result = log_config_finalize(&test_config);

    TEST_ASSERT(!result);
}
