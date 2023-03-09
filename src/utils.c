/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:31:00 by csenand           #+#    #+#             */
/*   Updated: 2023/03/09 13:53:42 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_err(const char *msg)
{
	printf("%sError%s: %s\n", R, RESET, msg);
	exit(1);
}

// void ft_err(const char *msg)
// {
//     printf("%sError%s: %s\n", R, RESET, msg);
//     exit(1);
// }