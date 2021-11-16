#include "common.h"

int	ft_stack_issort(t_stack *stack_a)
{
	while (stack_a->prev)
	{
		if (stack_a->prev->nbr < stack_a->nbr)
			return (0);
		stack_a = stack_a->prev;
	}
	return (1);
}

void	ft_stackadd_back(t_stack **stack, t_stack *node)
{
	t_stack *cursor;

	cursor = *stack;
	if (!(*stack))
		*stack = node;
	else
	{
		while (cursor->prev)
		{
			cursor = cursor->prev;
		}
		cursor->prev = node;
	}
}

t_stack	*ft_copy_stack(t_stack *stack)
{
	t_stack *new;
	t_stack	*node;

	new = NULL;
	node = NULL;
	while (stack)
	{
		if(!(node = (t_stack *)malloc(sizeof(t_stack))))
		{
			ft_free_stack(&new);
			return (NULL);
		}
		node->nbr = stack->nbr;
		node->prev = NULL;
		ft_stackadd_back(&new, node);
		stack = stack->prev;
	}
	return (new);
}
