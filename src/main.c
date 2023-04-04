
#include "../include/push_swap.h"

// TODO mettre des 'static' en debut de fonction (lorsque qu'elles sont 
//	   utilisee seulement dans le fichier actuel)
// TODO check final de tous les headers (loulou vs csenand)
// TODO se below

/*
**	ISSUES TO FIX
**	- minor leaks w/ only a space : ./push_swap " "
**	- TLE on basic test
**	- double check w/ valgrind about free in is_sorted
**	- 2 edge case w/ 5 nbrs when it's in descending order (./push_swap 5 4 3 2 1) 
*/


int	main(int ac, char **av)
{
	t_stack	*m_stack;

	if (ac >= 2)
	{
		m_stack = malloc(sizeof(t_stack));
		if (!m_stack)
			return (1);
		ft_m_stack_init(m_stack);
		ft_parse(ac, av, m_stack);
		ft_assign_index(m_stack->a, m_stack->m_size);
		ft_sort_algo(m_stack);
		ft_free_stack(&m_stack->a);
		ft_free_stack(&m_stack->b);
		ft_free_m_stack(&m_stack);
	}
	return (0);
}
