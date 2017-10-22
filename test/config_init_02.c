
# include "testing.h"

static struct log_config test_config = { "test", NULL, NULL, false, false };


/**
 * Test config initialization (config w/o type)
 */
TEST_CASE{

    bool result;
    
    result = log_config_initialize(&test_config);

    TEST_ASSERT(!result);									
    TEST_ASSERT(!test_config.is_initialized);				
}
