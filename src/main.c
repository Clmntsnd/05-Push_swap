/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:28:35 by loulou            #+#    #+#             */
/*   Updated: 2023/03/20 16:02:34 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	Parsing :
**	 - No letters
**	 - No duplicates (twice the same nb)
**	 - No int above int_max (2147483647) or below int_min (-2147483648)
*/

void print_list(t_node *stack_a)
{
    while (stack_a) 
	{
        printf("%d ", stack_a->data);
        stack_a = stack_a->next;
    }
    printf("\n");
}

void	ft_parse_arg(int ac, char **av)
{
	t_node	*stack_a;
	int 	i;
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
				ft_err("Data isn't valid\n");
		}
		ft_ps_addback(&stack_a, ft_ps_new_node((int)nb));
		printf("nbr : %ld\n", nb);
		i++;
	}
		print_list(stack_a);
}

int main(int ac, char **av)
{
	if (ac < 2)
		printf("%sError%s\n", R, RESET);
	if (ac >= 2)
	{
		ft_parse_arg(ac, av);
		//TODO add structure and returns it once filled
		//TODO print the returned stack/pile of nbs
	}
	else
		//TODO create free fts
	return (0);
}
