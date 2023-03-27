/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:56:20 by csenand           #+#    #+#             */
/*   Updated: 2023/03/27 14:13:35 by loulou           ###   ########.fr       */
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
	int				s_size;
	int				s_index;
	struct s_node 	*next;
	struct s_node 	*previous;
} t_node;

typedef struct s_move
{
	char			*push_a;
	char			*push_b;
	char			*swap;
	char			*swap_a;
	char			*swap_b;
	char			*rotate;
	char			*rotate_a;
	char			*rotate_b;
	char			*reverse;
	char			*reverse_a;
	char			*reverse_b;
}					t_move;

/*
**	Print message
*/
// void	ft_err(const char *msg);
void	ft_err(const char *msg, t_node *stack);
t_move	*ft_print_moves(void);

/*
**	Node related functions
*/
void	ft_ps_addback(t_node **stack, t_node *new);
t_node	*ft_ps_new_node(int content);
void	ft_check_duplicates(t_node *stack);
// int 	ft_check_duplicates(t_node *stack);

/*
**	Move related functions
*/
void	ft_ps_push(t_node **from, t_node **to, char *move);
void	ft_ps_swap(t_node **stack, char *move);
void	ft_ps_rot(t_node **stack, char *move);
void	ft_ps_rev_rot(t_node **stack, char *move);

/*
**	Clear list
*/
void	ft_ps_lstdelone(t_node *lst);
void	ft_ps_lstclear(t_node **lst);

/*
**	Algo related functions
*/
void	ft_sort_algo(t_node *stack);
void	ft_assign_index(t_node *stack, int size);
int		ft_ps_index_max(t_node *stack);
int		ft_ps_index_min(t_node *stack);

