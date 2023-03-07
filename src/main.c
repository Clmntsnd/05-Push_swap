/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:28:35 by loulou            #+#    #+#             */
/*   Updated: 2023/03/07 15:22:25 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	Parsing :
**	 - No letters
**	 - No duplicates (twice the same nb)
**	 - No int above int_max (2147483647) or below int_min (-2147483648)
*/
void check_arg(int ac, char **av)
{
	/*
	** case with several args
	*/
	if (ac > 2)
	{
		int i;
		int j;
		int flag;
		
		i = 0;
		while (i < ac)
		{
			j = 0;
			flag = 0;
			while (av[++i])
			{
				if ((av[i][j] == '-' || av[i][j] == '+') && av[i][j] != '\0')
					j++;
				if (!ft_isdigit(av[i][j]))
					flag = 1;
				if((ft_atoi(av[i]) == -2147483648) || (ft_atoi(av[i]) == 2147483647))
					flag = 2;
				if (flag == 1 || flag == 2)
				{
					printf("%sError%s\n", R, RESET);
					exit (1);
				}
			}
			// i++;
		}
	}
	
	/*
	** case with only one arg (i.e. string)
	*/
	if (ac == 2)
	{
		int		i;
		int		j;
		int 	flag;
		char	**tab;

		tab = ft_split(av[1], ' ');
		if (!tab)
			printf("%sError%s\n", R, RESET);
		i = - 1;
		while (tab[++i])
		{
			flag = 0;
			j = 0;
			if ((tab[i][j] == '-' || tab[i][j] == '+') && tab[i][j] != '\0')
				j++;
			if (!ft_isdigit(tab[i][j]))
				flag = 1;
			if((ft_atoi(tab[i]) == INT_MIN) || (ft_atoi(tab[i]) == INT_MAX))
				flag = 2;
			if (flag == 1 || flag == 2)
			{
				printf("%sError%s\n", R, RESET);
				exit (1);
			}
		}
	}
	printf("%sAll args are acceptable ✅\n%s", G, RESET);
}

int main(int ac, char **av)
{
	if (ac < 2)
		printf("%sError%s\n", R, RESET);
	if (ac >= 2)
		check_arg(ac, av);
	return (0);
}
