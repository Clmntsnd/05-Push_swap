
#include "../include/push_swap.h"

/*
**	Parsing :
**		- No letters
**		- No duplicates (twice the same nb)
**		- No int above int_max (2147483647) or below int_min (-2147483648)
**
*/

// void	print_list(t_node *stack)
// {
// 	while (stack)
// 	{
// 		printf("%d ", stack->data);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

void	ft_m_stack_init(t_stack *m_stack)
{
	m_stack->a = NULL;
	m_stack->b = NULL;
	m_stack->m_size = 0;
}

int	ft_parse_arg(int ac, char **av, t_stack *m_stack)
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
			{
				ft_free_stack(&m_stack->a);
				ft_free_m_stack(&m_stack);
				ft_err("Data isn't valid\n");
			}
		}
		ft_ps_addback(&m_stack->a, ft_ps_new_node((int)nb));
		m_stack->m_size++;
		i++;
	}
	ft_check_duplicates(m_stack, m_stack->a);
	return(1);
}

int	main(int ac, char **av)
{
	t_stack	*m_stack;
	
	if (ac > 1)
	{
		// printf("Parsing start ...\n\n");
		m_stack = malloc(sizeof(t_stack));
		if (!m_stack)
			return (1);
		ft_m_stack_init(m_stack);
		if (ft_parse_arg(ac, av, m_stack) != 0)
		{
			// printf("Parsing valid\n\n");
			// printf("Stack_a's data : \n");
			// print_list(m_stack->a);
			ft_assign_index(m_stack->a, m_stack->m_size);
			ft_sort_algo(m_stack);
			ft_free_stack(&m_stack->a);
			ft_free_m_stack(&m_stack);
		}		
	}
	return (0);
	//TODO mettre des 'static' en debut de fonction (lorsque qu'elles sont utilisee seulement dans le fichier actuel)
	//TODO check final de tous les headers (loulou vs csenand)
}
