/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:35:19 by csenand           #+#    #+#             */
/*   Updated: 2023/04/03 12:09:51 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*		Display Error on the command line after freeing all the stacks	*/
void	ft_err(t_stack *m_stack)
{
	ft_free_stack(&m_stack->a);
	ft_free_m_stack(&m_stack);
	printf("%sError%s\n", R, RESET);
	exit(1);
}

/*		Check for duplicates	*/
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
				ft_err(m_stack);
			runner = runner->next;
		}
		current = current->next;
	}
}

/*		Parsing the inputted numbers (works only for several args)	*/
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
				ft_err(m_stack);
		}
		ft_ps_addback(&m_stack->a, ft_ps_new_node((int)nb));
		m_stack->m_size++;
		i++;
	}
	ft_check_duplicates(m_stack, m_stack->a);
	return (1);
}
