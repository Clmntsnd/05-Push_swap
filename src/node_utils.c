//TODO put 42 header here

#include "../include/push_swap.h"

void	ft_ps_addback(t_node **stack, t_node *data_in)
{
	t_node	*add_last;

	if (!data_in)
		return ;
	if (!(*stack))
	{
		*stack = data_in;
		return ;
	}
	add_last = *stack;
	while (add_last->next != NULL)
		add_last = add_last->next;
	add_last->next = data_in;
	// new->previous = add_last;
}

t_node	*ft_ps_new_node(int data)
{
	t_node	*new_node;
	
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = -1; 
	//TODO why index = -1 ??
	new_node->next = NULL;
	// new_node->previous = NULL;
	return (new_node);
}

void	ft_free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	ft_free_m_stack(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	free(*stack);
	*stack = NULL;
}