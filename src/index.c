/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:34:04 by csenand           #+#    #+#             */
/*   Updated: 2023/03/30 17:48:58 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_assign_index(t_node *stack, int size)
{
	int		i;
	t_node	*max;
	t_node	*temp;

	max = NULL;
	temp = stack;
	while (size > 0)
	{
		i = 0;
		while (temp != NULL)
		{
			if ((i <= temp->data) && temp->index == -1)
			{
				i = temp->data;
				max = temp;
			}
			temp = temp->next;
		}
		max->index = size;
		temp = stack;
		size--;
	}
}

int	ft_ps_index_max(t_node *stack)
{
	int		max;
	t_node	*temp;
	int		max_bits;

	temp = stack;
	max = INT_MIN;
	max_bits = 0;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_radix(t_stack *m_stack, t_move *move)
{
	t_node	*temp;
	int		i;
	int		j;
	int		max;
	int		size;

	temp = m_stack->a;
	size = ft_ps_stack_size(m_stack->a);
	max = ft_ps_index_max(m_stack->a);
	i = 0;
	while (i < max)
	{
		j = 0;
		while (j++ < size)
		{
			temp = m_stack->a;
			if (((temp->index >> i) & 1) == 1)
				ft_ps_rot(&m_stack->a, move->rotate_a);
			else
				ft_ps_push(&m_stack->a, &m_stack->b, move->push_b);
		}
		while (ft_ps_stack_size(m_stack->b) != 0)
			ft_ps_push(&m_stack->b, &m_stack->a, move->push_a);
		i++;
	}
}
