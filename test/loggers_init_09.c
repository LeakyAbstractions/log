
# include "testing.h"

static bool initialized_appender = false;
static bool initialized_layout = false;
static bool initialize_appender(struct log_appender * appender);
static bool initialize_layout(struct log_layout * layout);
static struct log_layout_type test_layout_type = { initialize_layout, NULL, NULL };
static struct log_appender_type test_appender_type = { initialize_appender, NULL, NULL };
static struct log_layout test_layout = { "test", &test_layout_type, NULL, false, false };
static struct log_appender test_appender = { "test", &test_appender_type, NULL, false, false };
static struct log_logger test_logger = { "test", &test_appender, &test_layout, 0, 100, false, false };
static struct log_logger * test_list[] = { &test_logger, NULL };


/**
 * Test logger list initialization (logger w/ appender and layout w/ types w/ initialize functions BUT w/o action function)
 */
TEST_CASE{

    bool result;

    test_appender_type.initialize = initialize_appender;
    test_layout_type.initialize = initialize_layout;
    result = log_loggers_initialize(test_list);
    TEST_ASSERT(!result);
    TEST_ASSERT(!test_logger.is_initialized);
    TEST_ASSERT(!initialized_appender);
    TEST_ASSERT(!initialized_layout);
    TEST_ASSERT(!test_appender.is_initialized);
    TEST_ASSERT(!test_layout.is_initialized);
}

static bool initialize_appender(struct log_appender * appender){

    (void)appender;

    initialized_appender = true;

    return(true);
}

static bool initialize_layout(struct log_layout * layout){

    (void)layout;

    initialized_layout = true;

    return(true);
}
