/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:21:51 by csenand           #+#    #+#             */
/*   Updated: 2023/03/23 14:31:57 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_push(t_node **from, t_node **to, char *move)
{
	if(!(*from))
		return ;
    if ((*from)->next)
    {
        t_node *tmp;

        tmp = *from;
        *from = (*from)->next;
        tmp->next = *to;
        *to = tmp;
    }
}