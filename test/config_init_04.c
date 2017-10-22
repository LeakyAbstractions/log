
# include "testing.h"

static bool initialized = false;
static bool initialize(struct log_config * config);
static struct log_config_type test_config_type = { initialize, NULL, NULL };
static struct log_config test_config = { "test", &test_config_type, NULL, false, false };


/**
 * Test config initialization (initialize function returns true)
 */
TEST_CASE{

    bool result;

    result = log_config_initialize(&test_config);

    TEST_ASSERT(result);
    TEST_ASSERT(test_config.is_initialized);
    TEST_ASSERT(initialized);
}

static bool initialize(struct log_config * config){

    TEST_ASSERT(config == &test_config);

    initialized = true;

    return(initialized);
}
