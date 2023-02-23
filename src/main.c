/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:28:35 by loulou            #+#    #+#             */
/*   Updated: 2023/02/23 10:42:43 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void check_arg(int ac, char **av)
{
	if (ac >= 2)
	{
		int i = 1;
		int j = 0;
		int flag = 0;
		/*
		** case with several args
		*/
		while (i < ac)
		{
			j = -1;
			while (av[i][++j])
			{
				printf("av : %c\n", (av[i][j]));
				if (!ft_isdigit(av[i][j]))
					flag = 1;
				// if((ft_atoi(&av[i][j]) == -2147483648) || (ft_atoi(&av[i][j]) == 2147483647)){
				// 	printf("flag int min/max\n");
				// 	flag = 1;
				// }
				printf("flag : %d\n", flag);
				if (flag == 1)
				{
					printf("Error\n");
					exit (1);
				}
				// j++;
			}
			i++;
		}
	}
	printf("push_swap could start");	
}

int main(int ac, char **av)
{
	// printf("Main Start\nac : %d\n", ac);
	// printf("av[1] : %s\nMain end\n\n", av[1]);
	check_arg(ac, av);
}

// ./push_swap 0 one 2 3
// ac == 5
// av[0] = push_swap
// av[1] = 0
// av[2] = one
// av[3] = 2
// av[4] = 3
// output ; ERROR