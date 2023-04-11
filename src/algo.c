/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:59:03 by csenand           #+#    #+#             */
/*   Updated: 2023/04/11 16:17:20 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*		Checks if nbrs are already sorted	*/
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

/*		Algo for 3 nbrs only		*/
void	ft_algo_3(t_stack *stack)
{
	int	max;

	max = ft_ps_max_value(stack->a);
	if (stack->a->index == max)
		ft_ps_rot(&stack->a, "ra");
	if (stack->a->next->index == max)
		ft_ps_rev_rot(&stack->a, "rra");
	if (stack->a->next->next
		&& stack->a->next->next->index == max
		&& stack->a->index > stack->a->next->index)
		ft_ps_swap(&stack->a, "sa");
}

/*		Algo for 4 nbrs (using the algo_3)	*/
void	ft_algo_4(t_stack *m_stack)
{
	while (ft_ps_stack_size(m_stack->a) > 3)
	{
		if (m_stack->a->index == ft_ps_min_value(m_stack->a))
			ft_ps_push(&m_stack->a, &m_stack->b, "pb");
		else
			ft_ps_rot(&m_stack->a, "ra");
	}
	ft_algo_3(m_stack);
	ft_ps_push(&m_stack->b, &m_stack->a, "pa");
}

/*		Algo for nbrs >3 and <= 5 (using the algo_3)	*/
void	ft_algo_5(t_stack *m_stack)
{
	while (ft_ps_stack_size(m_stack->a) > 3)
	{
		if (m_stack->a->index == 1 || m_stack->a->index == 2)
			ft_ps_push(&m_stack->a, &m_stack->b, "pb");
		else
			ft_ps_rot(&m_stack->a, "ra");
	}
	ft_algo_3(m_stack);
	while (ft_ps_stack_size(m_stack->b) > 0)
	{
		if (m_stack->b->index == ft_ps_max_value(m_stack->b))
			ft_ps_push(&m_stack->b, &m_stack->a, "pa");
		else
			ft_ps_rot(&m_stack->b, "rb");
	}
}

/*		Fct that parse the stacks per their size	*/
void	ft_sort_algo(t_stack *m_stack)
{
	if (ft_ps_stack_size(m_stack->a) == 1)
		return ;
	if (ft_check_sorted(m_stack->a) == 1)
		return ;
	else if (m_stack->m_size == 2)
		ft_ps_swap(&m_stack->a, "sa");
	else if (m_stack->m_size == 3)
		ft_algo_3(m_stack);
	else if (m_stack->m_size == 4)
		ft_algo_4(m_stack);
	else if (m_stack->m_size == 5)
		ft_algo_5(m_stack);
	else
		ft_radix(m_stack);
}
