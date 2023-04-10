/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:48:23 by csenand           #+#    #+#             */
/*   Updated: 2023/04/07 12:52:32 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../lib/Libft/include/libft.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*a;
	t_node			*b;
	int				m_size;
}					t_stack;

/*
**	Parsing
*/
void	ft_parse(int ac, char **av, t_stack *m_stack);

/*
**	Print Error message
*/
void	ft_err(t_stack *m_stack);

/*
**	Node related functions
*/
void	ft_m_stack_init(t_stack *m_stack);
void	ft_ps_addback(t_node **stack, t_node *data_in);
t_node	*ft_ps_new_node(int content);
void	ft_check_duplicates(t_stack *m_stack, t_node *stack);
int		ft_ps_stack_size(t_node *stack);

/*
**	Move related functions
*/
void	ft_ps_push(t_node **from, t_node **to, char *move);
void	ft_ps_swap(t_node **stack, char *move);
void	ft_ps_rot(t_node **stack, char *move);
void	ft_ps_rev_rot(t_node **stack, char *move);

/*
**	Free related functions
*/
void	ft_free_m_stack(t_stack **stack);
void	ft_free_stack(t_node **stack);
char	*ft_free_tab(char **tab);

/*
**	Algo related functions
*/
void	ft_sort_algo(t_stack *m_stack);
void	ft_assign_index(t_node *stack, int size);
int		ft_ps_max_digits(t_node *stack);
int		ft_ps_min_value(t_node *stack);
int		ft_ps_max_value(t_node *stack);
void	ft_radix(t_stack *m_stack);

#endif