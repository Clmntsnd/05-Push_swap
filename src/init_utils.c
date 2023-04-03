//TODO 42header

#include "../include/push_swap.h"

/*		Init 'm_stack' that'll host stack_a and stack_b	*/
void	ft_m_stack_init(t_stack *m_stack)
{
	m_stack->a = NULL;
	m_stack->b = NULL;
	m_stack->m_size = 0;
}

/*		Init 'moves' struct to list all the moves to print	*/
t_move	*ft_print_moves(void)
{
	t_move	*moves;

	moves = malloc(sizeof(t_move));
	if (!moves)
		return (NULL);
	moves->push_a = "pa";
	moves->push_b = "pb";
	moves->swap_a = "sa";
	moves->swap_b = "sb";
	moves->rotate_a = "ra";
	moves->rotate_b = "rb";
	moves->reverse_a = "rra";
	moves->reverse_b = "rrb";
	return (moves);
}