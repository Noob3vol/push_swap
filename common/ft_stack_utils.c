/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:43:48 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/21 14:30:42 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_stack	*cursor;

	cursor = *stack;
	if (!node)
		return ;
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
	t_stack	*new;
	t_stack	*node;

	new = NULL;
	node = NULL;
	while (stack)
	{
		node = (t_stack *)malloc(sizeof(t_stack));
		if (!(node))
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
