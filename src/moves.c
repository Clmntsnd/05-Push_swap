/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:34:53 by csenand           #+#    #+#             */
/*   Updated: 2023/04/11 16:17:29 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*		Push either stack_a or stack_b		*/
void	ft_ps_push(t_node **from, t_node **to, char *move)
{
	t_node	*tmp;

	if (!(*from))
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	printf("%s\n", move);
}

/*		Swap either stack_a or stack_b		*/
void	ft_ps_swap(t_node **stack, char *move)
{
	t_node	*tmp;

	if (!stack || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	printf("%s\n", move);
}

/*		Rotate either stack_a or stack_b		*/
void	ft_ps_rot(t_node **stack, char *move)
{
	t_node	*tmp;
	t_node	*last;

	tmp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	printf("%s\n", move);
}

/*		Reverse rotate either stack_a or stack_b		*/
void	ft_ps_rev_rot(t_node **stack, char *move)
{
	t_node	*last;
	t_node	*prev;

	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *stack;
	prev->next = NULL;
	*stack = last;
	printf("%s\n", move);
}
