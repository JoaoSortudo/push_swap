#include "push_swap.h"

int main(int argc, char **argv) {
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2) {
        write(2, "Error\n", 6);
        return (1);
    }

    stack_a = init_stack();
    stack_b = init_stack();
    if (!stack_a || !stack_b) {
        write(2, "Error\n", 6);
        return (1);
    }

    if (!fill_stack(stack_a, argc, argv)) {
        write(2, "Error\n", 6);
        free_stack(stack_a);
        free_stack(stack_b);
        return (1);
    }

    sort(stack_a, stack_b);

    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}
