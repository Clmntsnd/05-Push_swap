
//TODO put 42 header here


#include "../include/push_swap.h"

void	ft_assign_index(t_node *stack, int size)
{
	int		i;
	t_node	*max;
	t_node	*temp;

	max = NULL;
	temp = stack;
	while (size > 0)
	{
		i = 0;
		while (temp != NULL)
		{
			if ((i <= temp->data) && temp->index == -1)
			{
				i = temp->data;
				max = temp;
			}
			temp = temp->next;
		}
		max->index = size;
		temp = stack;
		size--;
	}
}

int	ft_ps_index_max(t_node *stack)
{
	int		max;
	t_node	*temp;

	max = INT_MIN;
	temp = stack;
	while(temp)
	{
		if(temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return(max);
}

int	ft_ps_index_min(t_node *stack)
{
	int		min;
	t_node	*temp;

	min = INT_MAX;
	temp = stack;
	while (temp)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	return (min);
}

void 	ft_radix(t_stack *m_stack, t_move *move)
{
	// t_stack *temp;
	int 	i;
	int 	j;
	int		max;

	// temp = m_stack; 
	max = ft_ps_index_max(m_stack->a); //le plus grd nombre
	i = 0;
	while (i < max)
	{
		j = 0;
		while(j++ < m_stack->m_size)
		{
			// temp = m_stack; 
			if(((m_stack->m_size >> i) & 1) == 1)
				ft_ps_rot(&m_stack->a, move->swap_a);
			else
				ft_ps_push(&m_stack->a, &m_stack->b, move->push_b);
		}
		while(m_stack->b)
			ft_ps_push(&m_stack->b, &m_stack->a, move->push_a);
		i++;
	}
}
