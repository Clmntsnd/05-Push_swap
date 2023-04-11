/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:58:50 by csenand           #+#    #+#             */
/*   Updated: 2023/04/11 16:17:27 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*m_stack;

	if (ac > 1)
	{
		m_stack = malloc(sizeof(t_stack));
		if (!m_stack)
			return (1);
		ft_m_stack_init(m_stack);
		ft_parse(ac, av, m_stack);
		ft_assign_index(m_stack->a, m_stack->m_size);
		ft_sort_algo(m_stack);
		ft_free_stack(&m_stack->a);
		ft_free_stack(&m_stack->b);
		ft_free_m_stack(&m_stack);
	}
	return (0);
}
