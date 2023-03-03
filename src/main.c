/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:28:35 by loulou            #+#    #+#             */
/*   Updated: 2023/03/03 15:59:21 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
**	Parsing :
**	 - No letters
**	 - No duplicates (twice the same nb)
**	 - No int above in_max (2147483647) or below int_min (-2147483648)
*/
void check_arg(int ac, char **av)
{
	if (ac >= 2)
	{
		int i;
		int j;
		int flag;
		
		/*
		** case with several args
		*/
		i = 1;
		while (i < ac)
		{
			j = -1;
			flag = 0;
			while (av[i][++j])
			{
				if ((av[i][j] == '-' || av[i][j] == '-') && av[i][j] != '\0')
					j++;
				if (!ft_isdigit(av[i][j]))
					flag = 1;
				if((ft_atoi(av[i]) == -2147483648) || (ft_atoi(av[i]) == 2147483647))
					flag = 2;
				// printf("flag : %d\n", flag);
				if (flag == 1 || flag == 2)
				{
					printf("%sError%s\n", R, RESET);
					exit (1);
				}
			}
			i++;
		}
	}
	printf("%sAll args are acceptable ✅\n%s", G, RESET);
}

int main(int ac, char **av)
{
	// printf("Main Start\nac : %d\n", ac);
	// printf("av[1] : %s\nMain end\n\n", av[1]);
	check_arg(ac, av);
}
