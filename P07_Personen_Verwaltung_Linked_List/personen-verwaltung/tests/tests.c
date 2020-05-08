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
#include "list.h"
#include "person.h"

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

#define TRACE_INDENT "\n                " ///< allow for better stdout formatting in case of error

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
static void test_person_compare(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	person_t a = (person_t) {"a", "a", 1};
	person_t aa = (person_t) {"a", "a", 2};
	person_t b = (person_t) {"b", "b", 2};
	// assert
	CU_ASSERT(person_compare(&a, &b) < 0);
	CU_ASSERT(person_compare(&a, &aa) < 0);

	CU_ASSERT(person_compare(&a, &a) == 0);
	CU_ASSERT(person_compare(&aa, &aa) == 0);
	CU_ASSERT(person_compare(&b, &b) == 0);

	CU_ASSERT(person_compare(&b, &a) > 0);
	CU_ASSERT(person_compare(&aa, &a) > 0);
	// END-STUDENTS-TO-ADD-CODE
}

static void test_list_insert(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	node_t *anchor = malloc(sizeof(node_t));
	*(anchor) = (node_t) {(person_t) {"", "", 0}, anchor};
	person_t a = (person_t) {"a", "a", 1};
	person_t b = (person_t) {"b", "b", 2};
	list_insert(anchor, &a);
	list_insert(anchor, &b);
	// assert
	CU_ASSERT(person_compare(&anchor->next->content, &a) == 0);
	CU_ASSERT(person_compare(&anchor->next->next->content, &b) == 0);
	// END-STUDENTS-TO-ADD-CODE
}

static void test_list_remove(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	node_t *anchor = malloc(sizeof(node_t));
	*(anchor) = (node_t) {(person_t) {"", "", 0}, anchor};
	person_t a = (person_t) {"a", "a", 1};

	list_insert(anchor, &a);
	list_remove(anchor, &a);
	// assert
	CU_ASSERT(anchor->next == anchor);
	CU_ASSERT(person_compare(&anchor->next->content,&anchor->content) == 0);
	// END-STUDENTS-TO-ADD-CODE
}

static void test_list_clear(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	node_t *anchor = malloc(sizeof(node_t));
	*(anchor) = (node_t) {(person_t) {"", "", 0}, anchor};
	person_t a = (person_t) {"a", "a", 1};
	person_t aa = (person_t) {"a", "a", 2};
	person_t b = (person_t) {"b", "b", 2};

	list_insert(anchor, &a);
	list_insert(anchor, &aa);
	list_insert(anchor, &b);
	list_clear(anchor);	
	// assert
	CU_ASSERT(anchor->next == anchor);
	CU_ASSERT(person_compare(&anchor->next->content,&anchor->content) == 0);
	// END-STUDENTS-TO-ADD-CODE
}

/**
 * @brief Registers and runs the tests.
 * @returns success (0) or one of the CU_ErrorCode (>0)
 */
int main(void)
{
    // setup, run, teardown
    TestMainBasic("lab test", setup, teardown
                  , test_person_compare
                  , test_list_insert
                  , test_list_remove
                  , test_list_clear
                  );
}
