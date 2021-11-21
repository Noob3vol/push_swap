/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_ruler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:43:24 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/17 16:52:56 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_stack_depth(t_stack *stack)
{
	int	depth;

	depth = 0;
	while (stack && ++depth)
		stack = stack->prev;
	return (depth);
}

int	ft_stack_ruler(t_stack *head, t_stack *beg, t_stack *end)
{
	int	len;

	if (beg == end)
		return (0);
	len = 0;
	while (beg && beg != end)
	{
		beg = beg->prev;
		len++;
	}
	if (beg)
		return (len);
	beg = head;
	while (beg && beg != end)
	{
		beg = beg->prev;
		len++;
	}
	return (len);
}

int	ft_stack_rt_dist(t_stack *head, t_stack *addr)
{
	t_stack	*cursor;
	int		distance;
	int		depth;

	if (head == addr)
		return (0);
	cursor = head;
	distance = 0;
	while (cursor != addr)
	{
		cursor = cursor->prev;
		distance++;
	}
	depth = ft_stack_depth(head);
	if (distance > depth / 2)
	{
		distance = depth - distance;
		distance = -distance;
	}
	return (distance);
}
