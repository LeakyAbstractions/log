
# include "testing.h"

int error_object = 123;


/**
 * Test event (null context)
 */
TEST_CASE{

    log_event_new(NULL, LOG_LEVEL_MIN, "test_function", "test_file", 123, &error_object, "Dummy event");
}
