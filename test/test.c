#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include <stack.h>

/** @file */

/**
 * @brief Shared stack fixture used by the unit tests.
 */
stack_t *stack = NULL;

/**
 * @brief Create and populate a stack before each test case runs.
 */
void setUp(void)
{
    stack = stack_new();
    stack_push(stack, 1);
    stack_push(stack, 3);
    stack_push(stack, 5);
}

/**
 * @brief Release the stack fixture after each test case.
 */
void tearDown(void)
{
    stack_delete(stack);
    stack = NULL;
}

/**
 * @brief Verify that a populated stack is reported as non-empty.
 */
void test_is_not_empty(void)
{
    TEST_ASSERT_FALSE(stack_is_empty(stack));
}

/**
 * @brief Verify that popping all elements leaves the stack empty.
 */
void test_is_empty(void)
{
    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);

    TEST_ASSERT_TRUE(stack_is_empty(stack));
}

/**
 * @brief Verify that pop returns elements in LIFO order.
 */
void test_pop(void) 
{
    TEST_ASSERT_EQUAL(5, stack_pop(stack));
    TEST_ASSERT_EQUAL(3, stack_pop(stack));
    TEST_ASSERT_EQUAL(1, stack_pop(stack));
}

/**
 * @brief Verify that top returns the current element without removing it.
 */
void test_top(void) 
{
    TEST_ASSERT_EQUAL(5, stack_top(stack)); // top element is not removed
    TEST_ASSERT_EQUAL(5, stack_top(stack));
}

/**
 * @brief Execute the Unity test suite for the stack module.
 *
 * @return Unity test runner exit status.
 */
int main(void)
{
	UNITY_BEGIN();
    	RUN_TEST(test_is_empty);
	RUN_TEST(test_is_not_empty);
	RUN_TEST(test_pop);
    	RUN_TEST(test_top);
	return UNITY_END();
}
