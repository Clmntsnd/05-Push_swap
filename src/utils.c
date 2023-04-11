/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:35:19 by csenand           #+#    #+#             */
/*   Updated: 2023/04/11 16:17:38 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*		Init 'm_stack' that'll host stack_a and stack_b	*/
void	ft_m_stack_init(t_stack *m_stack)
{
	m_stack->a = NULL;
	m_stack->b = NULL;
	m_stack->m_size = 0;
}

/*		Display Error on the command line after freeing all the stacks	*/
void	ft_err(t_stack *m_stack)
{
	ft_free_stack(&m_stack->a);
	ft_free_m_stack(&m_stack);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
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

char	*ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}
