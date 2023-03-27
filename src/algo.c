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

void	ft_algo_3(t_node *stack, t_move *move)
{
	int	max;

	max = ft_ps_index_max(stack);
	if (stack->s_index == max)
		ft_ps_rot(&stack, move->rotate_a);
	if (stack->next->s_index == max)
		ft_ps_rev_rot(&stack, move->reverse_a);
	if (stack->next->next->s_index == max
		&& stack->s_index > stack->next->s_index)
		ft_ps_swap(&stack, move->swap_a);
}

void	ft_sort_algo(t_node *stack)
{
	t_move	*move;

	move = ft_print_moves();
	if (ft_check_sorted(stack) == 1)
		exit(EXIT_SUCCESS);
	if (stack->s_size == 2)
		ft_ps_swap(&stack, move->swap_a);
	else if (stack->s_size == 3)
		ft_algo_3(stack, move);
}
