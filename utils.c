#include "push_swap.h"

void print_stack(t_stack *stack) {
    t_node *current = stack->top;
    while (current) {
        ft_printf("%d\n", current->value);
        current = current->next;
    }
}
