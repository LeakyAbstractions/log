
# include "testing.h"

struct log_context test_context = { "test_module", NULL, NULL, NULL, LOG_LEVEL_MIN, false };
int error_object = 123;


/**
 * Test event (null logger list)
 */
TEST_CASE{

    log_event_new(&test_context, LOG_LEVEL_MIN, "test_function", "test_file", 123, &error_object, "Dummy event");
}
