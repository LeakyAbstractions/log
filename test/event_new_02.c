
# include "testing.h"

static struct log_logger * test_list[] = { NULL };
struct log_context test_context = { "test_module", test_list, NULL, NULL, LOG_LEVEL_MIN, false };
int error_object = 123;


/**
 * Test event (empty logger list)
 */
TEST_CASE{

    log_event_new(&test_context, LOG_LEVEL_MIN, "test_function", "test_file", 123, &error_object, "Dummy event");
}
