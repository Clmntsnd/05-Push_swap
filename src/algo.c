//TODO put 42 header here


#include "../include/push_swap.h"

int	ft_check_sorted(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->next->data < temp->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_algo_3(t_stack *stack, t_move *move)
{
	int	max;

	max = ft_ps_index_max(stack->a);
	if (stack->a->index == max)
		ft_ps_rot(&stack->a, move->rotate_a);
	if (stack->a->next->index == max)
		ft_ps_rev_rot(&stack->a, move->reverse_a);
	if (stack->a->next->next->index == max
		&& stack->a->index > stack->a->next->index)
		ft_ps_swap(&stack->a, move->swap_a);
}

void	ft_sort_algo(t_stack *m_stack)
{
	t_move	*move;

	move = ft_print_moves();
	if (ft_check_sorted(m_stack->a) == 1)
		exit(EXIT_SUCCESS);
	if (m_stack->m_size == 2)
		ft_ps_swap(&m_stack->a, move->swap_a);
	else if (m_stack->m_size == 3)
		ft_algo_3(m_stack, move);
}
