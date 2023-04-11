/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:34:41 by csenand           #+#    #+#             */
/*   Updated: 2023/04/11 16:17:34 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_isnumber(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == 43 || argv[i] == 45) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]) == 1)
		i++;
	if (ft_isdigit(argv[i]) == 0 && argv[i] != '\0')
		return (0);
	return (1);
}

/*		Parsing the inputted numbers (works only for several args)	*/
static	int	ft_parse_args(int ac, char **av, t_stack *m_stack)
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
			if (!ft_isnumber(av[i]) || nb < INT_MIN || nb > INT_MAX)
				ft_err(m_stack);
		}
		ft_ps_addback(&m_stack->a, ft_ps_new_node((int)nb));
		m_stack->m_size++;
		i++;
	}
	return (1);
}

static int	ft_parse_string(char **s, t_stack *m_stack)
{
	int		i;
	int		j;
	long	nb;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			nb = ft_atol(s[i]);
			if ((s[i][j] == '-' || s[i][j] == '+') && s[i][j] != '\0')
				j++;
			if (!ft_isnumber(s[i]) || nb < INT_MIN || nb > INT_MAX)
				ft_err(m_stack);
		}
		ft_ps_addback(&m_stack->a, ft_ps_new_node((int)nb));
		m_stack->m_size++;
	}
	ft_free_tab(s);
	return (1);
}

void	ft_parse(int ac, char **av, t_stack *m_stack)
{
	char	**s;

	if (ac == 2)
	{
		s = ft_split(av[1], ' ');
		if (!s[0])
		{
			ft_free_tab(s);
			ft_err(m_stack);
		}
		ft_parse_string(s, m_stack);
	}
	if (ac > 2)
		ft_parse_args(ac, av, m_stack);
	if (m_stack->m_size > 1)
		ft_check_duplicates(m_stack, m_stack->a);
}
