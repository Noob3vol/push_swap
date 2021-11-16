/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_gather_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:09:51 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/01 23:19:04 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_prev(t_stack *head, t_stack *node)
{
	if (!node->prev)
		return (head);
	return (node->prev);
}

t_stack	*ft_stack_next(t_stack *head, t_stack *node)
{
	if (head == node)
		return (ft_stack_last_node(head));
	while (head && head->prev != node)
		head = head->prev;
	return (head);
}

t_stack	*ft_stack_last_node(t_stack *a)
{
	while (a->prev)
		a = a->prev;
	return (a);
}

t_stack	*ft_stack_highest(t_stack *stk)
{
	t_stack	*highest;

	if (!stk)
		return (NULL);
	highest = stk;
	while (stk)
	{
		if (stk->nbr > highest->nbr)
			highest = stk;
		stk = stk->prev;
	}
	return (highest);
}

t_stack	*ft_stack_min(t_stack *a)
{
	t_stack	*min;

	if (!a)
		return (NULL);
	min = a;
	while (a)
	{
		if (a->nbr < min->nbr)
			min = a;
		a = a->prev;
	}
	return (min);
}
