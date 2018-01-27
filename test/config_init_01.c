
# include "testing.h"

static struct log_config test_config = { "test", NULL, NULL, true, false };


/**
 * Test config initialization (config already initialized)
 */
TEST_CASE{

    bool result;

    result = log_config_initialize(&test_config);

    TEST_ASSERT(!result);
}
