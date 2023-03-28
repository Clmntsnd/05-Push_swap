/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:26:10 by csenand           #+#    #+#             */
/*   Updated: 2023/03/28 13:53:57 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ps_addback(t_node **stack, t_node *data_in)
{
	t_node	*add_last;
	printf("add_back starts\n");
	if (!data_in)
		return ;
	printf("add_back step 1 ok\n");
	if (!(*stack))
	{
		*stack = data_in;
		return ;
	}
	printf("add_back step 2 ok\n");
	add_last = *stack;
	printf("add_back step 3 ok\n");
	while (add_last->next != NULL)
	{
		add_last = add_last->next;
		printf("while loop ...\n");	
	}
	printf("add_back step 4 ok\n\n");
	add_last->next = data_in;
	// new->previous = add_last;
}

t_node	*ft_ps_new_node(int data)
{
	t_node	*new_node;
	printf("new_node start\n");
	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = -1; 
	//TODO why index = -1 ??
	new_node->next = NULL;
	// new_node->previous = NULL;
	printf("new_node end\n\n");
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
	t_node	*temp;

	if (!stack)
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