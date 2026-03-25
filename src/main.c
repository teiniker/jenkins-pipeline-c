#include <stdio.h>

#include <stack.h>

static void reverse_array(int values[], size_t length)
{
    stack_t *stack = stack_new();

    for(size_t i = 0; i < length; i++)
    {
        stack_push(stack, values[i]);
    }

    for(size_t i = 0; i < length; i++)
    {
        values[i] = stack_pop(stack);
    }

    stack_delete(stack);
}

static void print_array(const int values[], size_t length)
{
    printf("[ ");
    for(size_t i = 0; i < length; i++)
    {
        printf("%d ", values[i]);
    }
    printf("]\n");
}

int main(void)
{
    int values[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(values) / sizeof(values[0]);

    printf("Original array: ");
    print_array(values, length);

    reverse_array(values, length);

    printf("Reversed array: ");
    print_array(values, length);

    return 0;
}
