/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:34:20 by csenand           #+#    #+#             */
/*   Updated: 2023/04/03 17:12:49 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//TODO mettre des 'static' en debut de fonction (lorsque qu'elles sont 
//	   utilisee seulement dans le fichier actuel)
//TODO faire le parsing de la string
//TODO check final de tous les headers (loulou vs csenand)

int	main(int ac, char **av)
{
	t_stack	*m_stack;

	// if (ac == 2)
	// 	return (0);
	if (ac >= 2)
	{
		m_stack = malloc(sizeof(t_stack));
		if (!m_stack)
			return (1);
		ft_m_stack_init(m_stack);
		if (ft_parse_arg(ac, av, m_stack) != 0)
		{
			ft_assign_index(m_stack->a, m_stack->m_size);
			ft_sort_algo(m_stack);
			ft_free_stack(&m_stack->a);
			ft_free_m_stack(&m_stack);
		}		
	}
	return (0);
}
