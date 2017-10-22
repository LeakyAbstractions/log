
# include "testing.h"

static bool finalized = false;
static bool finalize(struct log_config * config);
static struct log_config_type test_config_type = { NULL, finalize, NULL };
static struct log_config test_config = { "test", &test_config_type, NULL, true, false };


/**
 * Test config finalization (finalize function returns true)
 */
TEST_CASE{

    bool result;

    result = log_config_finalize(&test_config);

    TEST_ASSERT(result);
    TEST_ASSERT(test_config.is_finalized);
    TEST_ASSERT(finalized);
}

static bool finalize(struct log_config * config){

    TEST_ASSERT(config == &test_config);

    finalized = true;

    return(true);
}
