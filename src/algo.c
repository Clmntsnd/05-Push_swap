/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:34:39 by csenand           #+#    #+#             */
/*   Updated: 2023/03/30 20:55:47 by loulou           ###   ########.fr       */
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
	if (stack->a->next->next->index == max
		&& stack->a->index > stack->a->next->index)
		ft_ps_swap(&stack->a, move->swap_a);
}

void	ft_algo_5(t_stack *stack, t_move *move)
{
	// Push the two smallest numbers to stack b
	while (ft_ps_stack_size(stack->b) < 2)
	{
		if (stack->a->index == ft_ps_min_value(stack->a))
			ft_ps_push(&stack->a, &stack->b, move->push_b);
		else
			ft_ps_rot(&stack->a, move->rotate_a);
	}

	// Sort the remaining three numbers on stack a
	ft_algo_3(stack, move);

	// Push the two smallest numbers from stack b back to stack a
	while (ft_ps_stack_size(stack->b) > 0)
	{
		if (stack->b->index == ft_ps_max_value(stack->b))
			ft_ps_push(&stack->b, &stack->a, move->push_a);
		else
			ft_ps_rot(&stack->b, move->rotate_b);
	}
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
