/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:34:04 by csenand           #+#    #+#             */
/*   Updated: 2023/04/11 16:17:24 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	Assigns an index for each numbers in the stack,
**	it's easier to work with index than the inputted nbrs
*/
void	ft_assign_index(t_node *stack, int size)
{
	int		i;
	t_node	*max;
	t_node	*temp;

	max = NULL;
	temp = stack;
	while (size > 0)
	{
		i = INT_MIN;
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

/*	Find the max value inside the stack		*/
int	ft_ps_max_value(t_node *stack)
{
	int		max;
	t_node	*temp;

	temp = stack;
	max = 0;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

/*	Find the max digits of the naax value inside the stack	*/
int	ft_ps_max_digits(t_node *stack)
{
	int	max;
	int	max_bits;

	max_bits = 0;
	max = ft_ps_max_value(stack);
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/*	Find the min value inside the stack		*/
int	ft_ps_min_value(t_node *stack)
{
	int		min;
	t_node	*temp;

	temp = stack;
	min = INT_MAX;
	while (temp)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	return (min);
}

/*	Radix algo to sort large numbers	*/
void	ft_radix(t_stack *m_stack)
{
	t_node	*temp;
	int		i;
	int		j;
	int		max;
	int		size;

	temp = m_stack->a;
	size = ft_ps_stack_size(m_stack->a);
	max = ft_ps_max_digits(m_stack->a);
	i = 0;
	while (i < max)
	{
		j = 0;
		while (j++ < size)
		{
			temp = m_stack->a;
			if (((temp->index >> i) & 1) == 1)
				ft_ps_rot(&m_stack->a, "ra");
			else
				ft_ps_push(&m_stack->a, &m_stack->b, "pb");
		}
		while (ft_ps_stack_size(m_stack->b) != 0)
			ft_ps_push(&m_stack->b, &m_stack->a, "pa");
		i++;
	}
}
