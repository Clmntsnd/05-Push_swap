/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:28:23 by loulou            #+#    #+#             */
/*   Updated: 2023/03/08 17:00:35 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../lib/Libft/libft.h"

# define G 		"\033[1;32m"
# define R		"\033[1;31m"
# define RESET	"\033[1;0m"

typedef struct s_stack
{
	int nbr; //nb qui vont etre stock dans une structure
	struct s_stack	*next;
} t_stack;

typedef struct s_node {
    int data;
    struct s_node *next;
} t_node;

void	ft_err();