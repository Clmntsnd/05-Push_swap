/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:26:10 by csenand           #+#    #+#             */
/*   Updated: 2023/03/20 16:26:14 by csenand          ###   ########.fr       */
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
}

t_node	*ft_ps_new_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}