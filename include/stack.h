#ifndef _LINKED_STACK_H_
#define _LINKED_STACK_H_

#include <stdio.h>
#include <stdbool.h>

/** @file */

/**
 * @brief A single stack node storing one integer value.
 */
typedef struct node 
{
    /** Stored integer value. */
    int value;
    /** Pointer to the next node in the stack. */
    struct node *next_ptr;
} node_t;

/**
 * @brief Linked stack handle.
 */
typedef struct  
{
    /** Pointer to the top element of the stack. */
    node_t *first_ptr;
} stack_t;

/**
 * @brief Allocate and initialize an empty stack.
 *
 * @return Pointer to the newly created stack.
 */
extern stack_t *stack_new();

/**
 * @brief Remove all nodes and free the stack itself.
 *
 * @param stack Stack instance to delete.
 */
extern void stack_delete(stack_t *stack);

/**
 * @brief Check whether the stack contains any elements.
 *
 * @param stack Stack instance to inspect.
 * @return true if the stack is empty, otherwise false.
 */
extern bool stack_is_empty(stack_t *stack);

/**
 * @brief Push a value onto the top of the stack.
 *
 * @param stack Stack instance to modify.
 * @param value Integer value to store.
 */
extern void stack_push(stack_t *stack, int value);

/**
 * @brief Remove and return the top value from the stack.
 *
 * @param stack Stack instance to modify.
 * @return The value removed from the top of the stack.
 */
extern int stack_pop(stack_t *stack);

/**
 * @brief Return the current top value without removing it.
 *
 * @param stack Stack instance to inspect.
 * @return The value stored at the top of the stack.
 */
extern int stack_top(stack_t *stack);

/**
 * @brief Print the stack contents from top to bottom.
 *
 * @param stack Stack instance to print.
 */
extern void stack_print(stack_t *stack);

#endif /* _LINKED_STACK_H_ */
