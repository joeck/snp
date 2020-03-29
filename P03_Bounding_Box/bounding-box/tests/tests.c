/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Test suite for the given package.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <assert.h>
#include <CUnit/Basic.h>
#include "test_utils.h"

#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief alias for EXIT_SUCCESS
#define OK   EXIT_SUCCESS
/// @brief alias for EXIT_FAILURE
#define FAIL EXIT_FAILURE

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

// setup & cleanup
static int setup(void)
{
    remove_file_if_exists(OUTFILE);
    remove_file_if_exists(ERRFILE);
    return 0; // success
}

static int teardown(void)
{
    // Do nothing.
    // Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
    return 0; // success
}

// tests
static void test_no_match(void)
{
    // arrange
    const char *out_txt[] = {
        "viewbox:-10.0:-10.0:250.0:290.0\n",
        "rect:0.0:0.0:100.0:200.0:gray\n",
        "polygon:0.0:220.0:230.0:220.0:100.0:270.0:green\n",
    };

    // act & assert
    CU_ASSERT_EQUAL(WEXITSTATUS(system(XSTR(TARGET) " 0/0-230/0-100/50 >" OUTFILE " 2>" ERRFILE)), OK);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_initial_match(void)
{
    // arrange
    const char *out_txt[] = {
        "viewbox:-10.0:-10.0:120.0:340.0\n",
        "rect:0.0:0.0:100.0:200.0:gray\n",
        "polygon:0.0:220.0:100.0:220.0:100.0:320.0:green\n",
        "polygon:0.0:0.0:100.0:0.0:100.0:100.0:yellow\n",
    };

    // act & assert
    CU_ASSERT_EQUAL(WEXITSTATUS(system(XSTR(TARGET) " 0/0-100/0-100/100 >" OUTFILE " 2>" ERRFILE)), OK);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_tight_match(void)
{
    // arrange
    const char *out_txt[] = {
        "viewbox:-10.0:-10.0:225.0:290.0\n",
        "rect:0.0:0.0:100.0:200.0:gray\n",
        "polygon:0.0:220.0:205.0:220.0:205.0:270.0:green\n",
        "polygon:94.8:0.0:48.7:199.7:0.0:188.5:yellow\n",
    };

    // act & assert
    CU_ASSERT_EQUAL(WEXITSTATUS(system(XSTR(TARGET) " 0/0-205/0-205/50 >" OUTFILE " 2>" ERRFILE)), OK);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}


/**
 * @brief Registers and runs the tests.
 * @returns success (0) or one of the CU_ErrorCode (>0)
 */
int main(void)
{
    // setup, run, teardown
    TestMainBasic("lab test", setup, teardown
                  , test_no_match
                  , test_initial_match
                  , test_tight_match
                  );
}
