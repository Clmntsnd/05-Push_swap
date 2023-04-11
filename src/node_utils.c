/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:35:03 by csenand           #+#    #+#             */
/*   Updated: 2023/04/11 16:17:31 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*		Fct that adds a node to the last created node	*/
void	ft_ps_addback(t_node **stack, t_node *data_in)
{
	t_node	*add_last;

	if (!data_in)
		return ;
	if (!(*stack))
	{
		*stack = data_in;
		return ;
	}
	add_last = *stack;
	while (add_last->next != NULL)
		add_last = add_last->next;
	add_last->next = data_in;
}

/*		Fct that creates a node		*/
t_node	*ft_ps_new_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

/*		Fct that calculates the stack's size	*/
int	ft_ps_stack_size(t_node *stack)
{
	int		i;
	t_node	*temp;

	if (stack == NULL)
		return (0);
	i = 0;
	temp = stack;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

/*		Fct that frees each stack (a or b)	*/
void	ft_free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/*		Fct that frees the 'm_stack'	*/
void	ft_free_m_stack(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	free(*stack);
	*stack = NULL;
}
