/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:28:23 by loulou            #+#    #+#             */
/*   Updated: 2023/03/14 18:06:35 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../lib/Libft/include/libft.h"

# define G 		"\033[1;32m"
# define R		"\033[1;31m"
# define RESET	"\033[1;0m"

typedef struct s_node 
{
	int 			data;
	struct s_node 	*next;
} t_node;

typedef struct s_info
{
	t_node	*a;
} t_info;

/*
**	Print Error Message
*/
void	ft_err(const char *msg);