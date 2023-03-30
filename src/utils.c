/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:35:19 by csenand           #+#    #+#             */
/*   Updated: 2023/03/30 17:53:58 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_m_stack_init(t_stack *m_stack)
{
	m_stack->a = NULL;
	m_stack->b = NULL;
	m_stack->m_size = 0;
}

void	ft_err(const char *msg, t_stack *m_stack)
{
	ft_free_stack(&m_stack->a);
	ft_free_m_stack(&m_stack);
	printf("%sError%s: %s\n", R, RESET, msg);
	exit(1);
}

void	ft_check_duplicates(t_stack *m_stack, t_node *stack)
{
	t_node	*current;
	t_node	*runner;

	current = stack;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->data == runner->data)
				ft_err("Duplicate data\n", m_stack);
			runner = runner->next;
		}
		current = current->next;
	}
}

int	ft_parse_arg(int ac, char **av, t_stack *m_stack)
{
	int		i;
	int		j;
	long	nb;

	i = 1;
	while (i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			nb = ft_atol(av[i]);
			if ((av[i][j] == '-' || av[i][j] == '+') && av[i][j] != '\0')
				j++;
			if (!ft_isdigit(av[i][j]) || nb < INT_MIN || nb > INT_MAX)
				ft_err("Data isn't valid\n", m_stack);
		}
		ft_ps_addback(&m_stack->a, ft_ps_new_node((int)nb));
		m_stack->m_size++;
		i++;
	}
	ft_check_duplicates(m_stack, m_stack->a);
	return (1);
}

t_move	*ft_print_moves(void)
{
	t_move	*moves;

	moves = malloc(sizeof(t_move));
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
