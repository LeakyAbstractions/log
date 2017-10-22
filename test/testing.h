
# ifndef TESTING_H
# define TESTING_H


# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <string.h>
# include <log.h>


/* Test Results */
# define TEST_RESULT_PASS   EXIT_SUCCESS
# define TEST_RESULT_SKIP   77
# define TEST_RESULT_FAIL   EXIT_FAILURE


/* Test Actions */
# define TEST_EXIT(RESULT)  exit(RESULT)
# define TEST_PASS          TEST_EXIT(TEST_RESULT_PASS)
# define TEST_SKIP          TEST_EXIT(TEST_RESULT_SKIP)
# define TEST_FAIL \
    do{ \
        (void)fprintf(stderr, "Failure at line: %d\n", __LINE__); \
        TEST_EXIT(TEST_RESULT_FAIL); \
    }while(0)


# define TEST_ASSERT(CHECK) \
    do{ \
        if( !(CHECK) ){ \
            (void)fprintf(stderr, "Assertion failed: %s (at line: %d)\n", #CHECK, __LINE__); \
            TEST_FAIL; \
        } \
    }while(0)
# define TEST_EQUALS(EXPECTED, FOUND) \
    do{ \
        if(strcmp((EXPECTED), (FOUND)) != 0){ \
            (void)fprintf(stderr, "Expecting: \"%s\". Found: \"%s\"\n", (EXPECTED), (FOUND)); \
            TEST_FAIL; \
        } \
    }while(0)

/* Test Cases */
# define TEST_CASE \
    \
    void test_case(void); \
    \
    int main(void){ \
        (void)printf("    - Running test %s...\n", __FILE__); \
        test_case(); \
        return(EXIT_SUCCESS); \
    } \
    \
    void test_case(void)


# endif
