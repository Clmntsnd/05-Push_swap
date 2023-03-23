/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:56:20 by csenand           #+#    #+#             */
/*   Updated: 2023/03/23 09:58:46 by csenand          ###   ########.fr       */
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
	int				s_index;
	struct s_node 	*next;
	struct s_node 	*previous;
} t_node;

/*
**	Print Error Message
*/
// void	ft_err(const char *msg);
void	ft_err(const char *msg, t_node *stack);

/*
**	Node related fonctions
*/
void	ft_ps_addback(t_node **stack, t_node *new);
t_node	*ft_ps_new_node(int content);
void	ft_check_duplicates(t_node *stack);
// int 	ft_check_duplicates(t_node *stack);

/*
**	Clear list
*/
void	ft_ps_lstdelone(t_node *lst);
void	ft_ps_lstclear(t_node **lst);