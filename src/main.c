/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:28:35 by loulou            #+#    #+#             */
/*   Updated: 2023/03/09 15:37:51 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	Parsing :
**	 - No letters
**	 - No duplicates (twice the same nb)
**	 - No int above int_max (2147483647) or below int_min (-2147483648)
*/

void	init()
{
	
}

void add_node(int data) //"lst_add_back"
{
    t_node	*new_node;
	
	new_node = malloc(sizeof(t_node));
    if (!new_node)
        return(0);
    new_node->data = data;
    new_node->next = NULL;
}

t_info check_arg(int ac, char **av)
{
	// t_stack	*head;
	// t_stack	*current;
	int i;
	
	/*
	** case with several args (valid)
	*/
	if (ac >= 2)
	{
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
				add_node(av[i]);
			}
			i++;
		}
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

int main(int ac, char **av)
{
	t_info	*gen_info;
	
	if (ac < 2)
		printf("%sError%s\n", R, RESET);
	if (ac >= 2)
		check_arg(ac, av);
	return (0);
}
