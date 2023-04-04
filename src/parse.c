//TODO 42header

#include "../include/push_swap.h"

void	print_list(t_node *stack_a)
{
	while (stack_a)
	{
		printf("%d ", stack_a->data);
		stack_a = stack_a->next;
	}
	printf("\n");
}

/*		Parsing the inputted numbers (works only for several args)	*/
int	ft_parse_args(int ac, char **av, t_stack *m_stack)
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
			if (!ft_isdigit(av[i][j]) || nb < INT_MIN || nb > INT_MAX)
				ft_err(m_stack);
		}
		ft_ps_addback(&m_stack->a, ft_ps_new_node((int)nb));
		m_stack->m_size++;
		i++;
	}
	return (1);
}

int	ft_parse_string(char **av, t_stack *m_stack)
{
	char	**s;
	int		i;
	int		j;
	long	nb;

	s = ft_split(av[1], 32);
	i = 0;
	if (!s[i])
		ft_err(m_stack);
	while (s[i])
	{
		j = -1;
		while (s[i][++j])
		{
			nb = ft_atol(s[i]);
			if ((av[i][j] == '-' || av[i][j] == '+') && av[i][j] != '\0')
				j++;
			if (!ft_isdigit(s[i][j]) || nb < INT_MIN || nb > INT_MAX)
				ft_err(m_stack);
		}
		ft_ps_addback(&m_stack->a, ft_ps_new_node((int)nb));
		m_stack->m_size++;
		i++;
	}
	ft_free_tab(s);
	return (1);
}

void	ft_parse(int ac, char **av, t_stack *m_stack)
{
	if (ac == 2)
		ft_parse_string(av, m_stack);
	if (ac > 2)
		ft_parse_args(ac, av, m_stack);
	if (m_stack->m_size > 1)
		ft_check_duplicates(m_stack, m_stack->a);
}
