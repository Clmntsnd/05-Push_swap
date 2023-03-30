//TODO put 42 header here

#include "../include/push_swap.h"

void ft_err(const char *msg, t_stack *m_stack)
{
	ft_free_stack(&m_stack->a);
	ft_free_m_stack(&m_stack);
    printf("%sError%s: %s\n", R, RESET, msg);
	exit(1);
}

void	ft_check_duplicates(t_stack *m_stack, t_node *stack)
{
    t_node *current;
    t_node *runner;
    
	current = stack;
    while (current != NULL) 
	{
        runner = current->next;
        while (runner != NULL) 
		{
            if (current->data == runner->data)
            {
                // ft_free_stack(&stack);
				// ft_free_m_stack(&m_stack);
                ft_err("Duplicate data\n", m_stack);
            }
            runner = runner->next;
        }
        current = current->next;
    }
}

t_move	*ft_print_moves(void)
{
	t_move	*moves;

	moves = malloc(sizeof(t_move));
	if (!moves)
		return (NULL);
	moves->push_a = "pa";
	moves->push_b = "pb";
	moves->swap = "ss";
	moves->swap_a = "sa";
	moves->swap_b = "sb";
	moves->rotate = "rr";
	moves->rotate_a = "ra";
	moves->rotate_b = "rb";
	moves->reverse = "rrr";
	moves->reverse_a = "rra";
	moves->reverse_b = "rrb";
	return (moves);
}