/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:26:10 by csenand           #+#    #+#             */
/*   Updated: 2023/03/27 14:08:21 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ps_addback(t_node **stack, t_node *new)
{
	t_node	*add_last;

	if (!stack || !new)
		return ;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	add_last = *stack;
	while (add_last->next != NULL)
		add_last = add_last->next;
	add_last->next = new;
	new->previous = add_last;
}

t_node	*ft_ps_new_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->s_index = 0;
	new_node->data = data;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

void	ft_ps_lstdelone(t_node *stack)
{
	if (!stack)
		return ;
	free(stack);
}

void	ft_ps_lstclear(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		ft_ps_lstdelone(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	ft_ps_lstsize(t_node *stack)
{
	int		i;
	t_node	*ptr_stack;

	if (!stack)
		return (0);
	i = 0;
	ptr_stack = stack;
	while (ptr_stack)
	{
		i++;
		ptr_stack = ptr_stack -> next;
	}
	return (i);
}