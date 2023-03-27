/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:31:00 by csenand           #+#    #+#             */
/*   Updated: 2023/03/27 11:06:33 by loulou           ###   ########.fr       */
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

t_move	*ft_print_moves(void)
{
	t_move	*moves;

	moves = malloc(sizeof(moves));
	if (!moves)
		return (NULL);
	moves->push_a = "pa";
	moves->push_b = "pb";
	moves->swap = "ss";
	moves->swap_a = "sa";
	moves->swap_b = "sb";
	moves->rotate = "rr";
	moves->rotate_a = "ra";
	moves->rotate_b = "rb";
	moves->reverse = "rrr";
	moves->reverse_a = "rra";
	moves->reverse_b = "rrb";
	return (moves);
}