/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:31:00 by csenand           #+#    #+#             */
/*   Updated: 2023/03/23 10:27:48 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_err(const char *msg, t_node *stack)
{
    (void)stack;
	// ft_ps_lstclear(&stack);
    printf("%sError%s: %s\n", R, RESET, msg);
	exit(1);
}

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
                ft_err("Duplicate data\n", stack);
            }
            runner = runner->next;
        }
        current = current->next;
    }
    
}
