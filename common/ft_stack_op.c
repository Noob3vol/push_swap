#include "stack.h"

void	ft_push_stack(t_stack **to_stack, t_stack **from_stack)
{
	t_stack *prev_to;

	if (!*from_stack)
		return ;
	prev_to = (*to_stack);
	*to_stack = *from_stack;
	*from_stack = (*from_stack)->prev;
	(*to_stack)->prev = prev_to;
}

void	ft_rotate_stack(t_stack **stack)
{
	t_stack *crawl;

	if (ft_stack_depth(*stack) < 2)
		return ;
	crawl = *stack;
	while (crawl->prev)
		crawl = crawl->prev;
	crawl->prev = *stack;
	*stack = (*stack)->prev;
	crawl->prev->prev = NULL;
}

void	ft_rev_rotate_stack(t_stack **stack)
{
	t_stack *crawl;
	t_stack *prev;

	if (ft_stack_depth(*stack) < 2)
		return ;
	crawl = *stack;
	while (crawl->prev)
	{
		prev = crawl;
		crawl = crawl->prev;
	}
	prev->prev = NULL;
	crawl->prev = *stack;
	*stack = crawl;
}

void	ft_swap_stack(t_stack **stack)
{
	t_stack *prev_prev;
	t_stack *prev;

	if (ft_stack_depth(*stack) < 2)
		return ;
	prev = (*stack)->prev;
	prev_prev = prev->prev;
	(*stack)->prev = prev->prev;
	prev->prev = (*stack);
	*stack = prev;
}

/*
**	void	ft_pa(t_stack **a, t_stack **b)
**	{
**		if (
**		ft_push_stack(b, a);
**	}
*/
