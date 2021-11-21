/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:06:01 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/01 22:06:03 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Serve as primitive for other checking function
*/
int	ft_node_ordered(t_stack *head, t_stack *node)
{
	t_stack	*min;
	t_stack	*max;
	t_stack	*prev;

	min = ft_stack_min(head);
	max = ft_stack_highest(head);
	prev = ft_stack_prev(head, node);
	if (node == max && prev == min)
		return (1);
	if (node->nbr < prev->nbr)
		return (1);
	return (0);
}

int	ft_stkprt_ordered(t_stack *head, t_stack *begin, t_stack *end)
{
	while (begin && begin != end)
	{
		if (!ft_node_ordered(head, begin))
			return (0);
		begin = ft_stack_prev(head, begin);
	}
	return (1);
}

/*
**  Stack Ordered is used in bubble sort
*/
int	ft_stack_ordered(t_stack *a)
{
	t_stack	*max;
	t_stack	*head;

	max = ft_stack_highest(a);
	head = (a);
	while (a)
	{
		if (!ft_node_ordered(head, a))
			return (0);
		a = a->prev;
	}
	return (1);
}
