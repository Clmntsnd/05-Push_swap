/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:34:39 by csenand           #+#    #+#             */
/*   Updated: 2023/03/31 12:53:23 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	max = ft_ps_max_value(stack->a);
	if (stack->a->index == max)
		ft_ps_rot(&stack->a, move->rotate_a);
	if (stack->a->next->index == max)
		ft_ps_rev_rot(&stack->a, move->reverse_a);
	if (stack->a->next->next
		&& stack->a->next->next->index == max
		&& stack->a->index > stack->a->next->index)
		ft_ps_swap(&stack->a, move->swap_a);
}

void	ft_algo_5(t_stack *stack, t_move *move)
{
	// Push the two smallest numbers to stack b

	// Sort the remaining three numbers on stack a
	ft_algo_3(stack, move);

	// Push the two smallest numbers from stack b back to stack a
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
	else if (m_stack->m_size <= 5)
		ft_algo_5(m_stack, move);
	else
		ft_radix(m_stack, move);
	free(move);
}
