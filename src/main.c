/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:28:35 by loulou            #+#    #+#             */
/*   Updated: 2023/03/15 17:45:20 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	Parsing :
**	 - No letters
**	 - No duplicates (twice the same nb)
**	 - No int above int_max (2147483647) or below int_min (-2147483648)
*/

t_node	*init_stack(t_node *stack)
{
	stack = malloc(sizeof(t_node));
	if(!stack)
		ft_err("Memory allocation failed");
	return(stack);
}

// void ft_add_node(int data)
// {
//     t_node	*new_node;
	
// 	new_node = malloc(sizeof(t_node));
//     if (!new_node)
//         return(0);
//     new_node->data = data;
//     new_node->next = NULL;
// }

void	ft_parse_arg(int ac, char **av, t_node **stack_a)
{
	int 	i;
	int		j;
	long	nb;
	int 	nbr;
	
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
			// ft_add_node(av[i]);
			nbr = ft_atoi(&av[i][j]);
			ft_lstadd_back((t_list **)stack_a, ft_lstnew(&nb));
		}
		i++;
	}
}

void print_list(t_node *stack_a)
{
    while (stack_a) 
	{
        printf("%d ", stack_a->data);
        stack_a = stack_a->next;
    }
    printf("\n");
}

// int main(int ac, char **av)
int main(int ac, char **av)
{
	t_node	*stack_a;
	
	if (ac < 2)
		printf("%sError%s\n", R, RESET);
	stack_a = NULL;
	if (ac >= 2)
	{
		stack_a = init_stack(stack_a);
		ft_parse_arg(ac, av, &stack_a);
		print_list(stack_a);
		//TODO add structure and returns it once filled
		//TODO print the returned stack/pile of nbs
	}
	else
		//TODO create free fts
	return (0);
}
