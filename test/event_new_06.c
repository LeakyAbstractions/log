
# include "testing.h"

static struct log_logger test_logger = { "test", NULL, NULL, 0, LOG_LEVEL_MAX, true, false };
static struct log_logger * test_list[] = { &test_logger, NULL };
struct log_context test_context = { "test_module", test_list, NULL, NULL, LOG_LEVEL_MIN, false };
int error_object = 123;


/**
 * Test event (inhibited logger)
 */
TEST_CASE{

    log_event_new(&test_context, LOG_LEVEL_MIN, "test_function", "test_file", 123, &error_object, "Dummy event");

    TEST_ASSERT(test_logger.sequence == 0);
}
