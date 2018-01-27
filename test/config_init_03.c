
# include "testing.h"

static struct log_config_type test_config_type = { NULL, NULL, NULL };
static struct log_config test_config = { "test", &test_config_type, NULL, false, false };


/**
 * Test config initialization (config type w/o initialize function)
 */
TEST_CASE{

    bool result;

    result = log_config_initialize(&test_config);

    TEST_ASSERT(result);
    TEST_ASSERT(test_config.is_initialized);
}
