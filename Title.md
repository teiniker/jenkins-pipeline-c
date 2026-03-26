# Stack

A stack is a linear data structure that stores elements according to the
**Last In, First Out (LIFO)** principle. The most recently inserted element is
the first one removed again. Typical stack operations are:

* **push**: insert a new element on the top of the stack
* **pop**: remove the current top element
* **top**: inspect the current top element without removing it
* **is empty**: check whether the stack contains any elements

Stacks are useful whenever data has to be processed in reverse order. Common
examples are function call handling, expression evaluation, undo/redo features,
or depth-first search. In this project, the stack is used to reverse an array:
the values are pushed onto the stack in their original order and popped again in
reverse order.


## Implementation Structure

The implementation is separated into a small reusable stack module and a simple
application that demonstrates how the module can be used.

The public interface is defined in `include/stack.h`. It declares the stack
types and the available operations such as `stack_new()`, `stack_push()`,
`stack_pop()`, and `stack_top()`. This header is the only part that application
code needs to include.

The linked-stack implementation itself is located in `src/stack.c`. Each stack
element is stored in a dynamically allocated node containing an integer value
and a pointer to the next node. The stack handle stores a pointer to the first
node, which represents the current top of the stack. Pushing an element creates
a new node and links it in front of the existing list. Popping removes that
first node again. This makes both operations efficient because they only update
the head pointer.

The demonstration program in `src/main.c` shows a practical use case. It
creates a stack, pushes all values of an integer array onto it, and then pops
the values back into the array. Because of the LIFO behavior, the resulting
array is reversed.


## Test Cases

The project contains automated unit tests in `test/test.c` based on the
**Unity** test framework. Each test starts from a defined fixture created in
`setUp()` and cleaned up in `tearDown()`. This keeps the tests isolated and
repeatable.

The test suite checks the most important stack properties:

* a populated stack is reported as non-empty
* removing all elements results in an empty stack
* `stack_pop()` returns elements in LIFO order
* `stack_top()` returns the current top element without removing it

These tests are intended to run automatically as part of the build process. In
a Jenkins pipeline, the code can be compiled and the test executable can be run
after every commit. This provides fast feedback: if a change breaks the stack
behavior, the pipeline fails immediately and the defect can be fixed before it
reaches later stages.

