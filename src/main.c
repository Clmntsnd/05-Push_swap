/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:28:35 by loulou            #+#    #+#             */
/*   Updated: 2023/03/14 18:07:53 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	Parsing :
**	 - No letters
**	 - No duplicates (twice the same nb)
**	 - No int above int_max (2147483647) or below int_min (-2147483648)
*/

t_info	*init_struct(t_info *strct)
{
	strct = malloc(sizeof(t_info));
	if(!strct)
		ft_err("Memory allocation failed");
	return(strct);
}

// void add_node(int data) //"lst_add_back"
// {
//     t_node	*new_node;
	
// 	new_node = malloc(sizeof(t_node));
//     if (!new_node)
//         return(0);
//     new_node->data = data;
//     new_node->next = NULL;
// }

void	check_arg(int ac, char **av)
{
	// t_stack	*head;
	// t_stack	*current;
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
			// add_node(av[i]);
		}
		i++;
	}
	// //creation de la premiere node avec le premier arg (i.e. av[1])
	// head = add_node(ft_atoi(av[1]));
	// //copy de la head pour ne pas la perdre
	// current = head;
	// //creation des autres nodes
	// i = 0;
	// while(i < ac)
	// 	ft_lstadd_back(av[i], current);
	// //Imprimmer la liste
	// current = head;
	// while (current->next)
	// {
	// 	printf("%d\n", current->nbr);
	// 	current = current->next;
	// }
}

// int main(int ac, char **av)
int main()
{

	printf("allo");
	
	// t_info	*main_struct;
	
	// main_struct = NULL;
	// if (ac < 2)
	// 	printf("%sError%s\n", R, RESET);
	// if (ac >= 2)
	// {
	// 	main_struct = init_struct(main_struct);
	// 	parse_arg(ac, av, main_struct);
	// 	//TODO add structure and returns it once filled
	// 	//TODO print the returned stack/pile of nbs
	// }
	// else
	// 	free(main_struct);
	// return (0);
}
