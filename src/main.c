/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:26:03 by csenand           #+#    #+#             */
/*   Updated: 2023/03/27 14:25:30 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	Parsing :
**		- No letters
**		- No duplicates (twice the same nb)
**		- No int above int_max (2147483647) or below int_min (-2147483648)
**
**	Algo :
**	Every chunk processing is as follows: 
**		- if the number belongs to the chunk (between start and end), then push it to stack b.
**
**
**
*/

void	print_list(t_node *stack_a)
{
	while (stack_a)
	{
		printf("%d ", stack_a->data);
		stack_a = stack_a->next;
	}
	printf("\n");
}

t_node	*ft_parse_arg(int ac, char **av)
{
	t_node	*stack_a;
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
				ft_err("Data isn't valid\n", stack_a);
		}
		ft_ps_addback(&stack_a, ft_ps_new_node((int)nb));
		stack_a->s_size++;
		i++;
	}
	ft_check_duplicates(stack_a);
	// print_list(stack_a);
	return(stack_a);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	
	stack_a = NULL;
	if (ac < 2)
		printf("%sError%s\n", R, RESET);
	if (ac > 1)
	{
		stack_a = ft_parse_arg(ac, av);
		ft_assign_index(stack_a, stack_a->s_size);
		ft_sort_algo(stack_a);
		//TODO add other fct here after the parsing is validated
		
	}
	ft_ps_lstclear(&stack_a);
	return (0);
	//TODO mettre des 'static' en debut de fonction (lorsque qu'elles sont utilisee seulement dans le fichier actuel)
	//TODO check final de tous les headers (loulou vs csenand)
}
