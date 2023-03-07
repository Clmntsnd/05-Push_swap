/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:34:44 by csenand           #+#    #+#             */
/*   Updated: 2023/03/07 15:19:50 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	Parsing :
**	 - No letters
**	 - No duplicates (twice the same nb)
**	 - No int above int_max (2147483647) or below int_min (-2147483648)
*/
void validate_arg(char **av, int i, int j)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	
	
}