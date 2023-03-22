/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:31:00 by csenand           #+#    #+#             */
/*   Updated: 2023/03/22 16:14:13 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_err(const char *msg)
{
	printf("%sError%s: %s\n", R, RESET, msg);
	exit(1);
}

// void	ft_check_duplicates(t_node *stack)
// {
// 	t_node	*node_1;
// 	t_node	*node_2;

// 	node_1 = stack;
// 	while (node_1->next)
// 	{
// 		node_2 = node_1->next;
// 		while (node_2->next)
// 		{
// 			if (node_1->data == node_2->data)
// 				ft_err("Duplicate data\n");
// 			node_2 = node_2->next;
// 		}
// 		if (node_2->next == NULL && node_1->data == node_2->data)
// 			ft_err("Data isn't valid\n");
// 		node_1 = node_1->next;
// 	}
// }

void	ft_check_duplicates(t_node *stack)
{
    t_node *current;
    t_node *runner;
    
	current = stack;
    while (current != NULL) 
	{
        runner = current->next;
        while (runner != NULL) 
		{
            if (current->data == runner->data)
            {
                // ft_ps_lstclear(&stack);
                ft_err("Duplicate data\n");
            }
            runner = runner->next;
        }
        current = current->next;
    }
    
}
