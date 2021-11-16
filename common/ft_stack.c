#include "stack.h"

t_stack *ft_init_stack(int value, t_stack *prev)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->prev = prev;
	new->nbr = value;
	return (new);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack *prev;

	while (*stack)
	{
		prev = (*stack)->prev;
		free(*stack);
		*stack = prev;
	}
}

/*
**	int	ft_push_value(int value, t_stack **stack)
**	{
**		t_stack *prev;
**		
**		prev = *stack;
**		if (!(*stack = (t_stack *)malloc(sizeof(t_stack))))
**			return (-1);
**		(*stack)->prev = prev;
**		(*stack)->nbr = value;
**		return (0);
**	}
*/
