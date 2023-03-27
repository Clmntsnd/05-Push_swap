
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
		i = INT_MIN;
		while (temp != NULL)
		{
			if ((i <= temp->data) && temp->s_index == -1)
			{
				i = temp->data;
				max = temp;
			}
			temp = temp->next;
		}
		max->s_index = size;
		temp = stack;
		size--;
	}
}

int	ft_ps_index_max(t_node *stack)
{
	int		max;
	t_node	*temp;

	max = 0;
	temp = stack;
	while(temp)
	{
		if(temp->s_index > max)
			max = temp->s_index;
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
		if (temp->s_index < min)
			min = temp->s_index;
		temp = temp->next;
	}
	return (min);
}
