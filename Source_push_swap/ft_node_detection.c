/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_detection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:47:51 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/07 12:47:54 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_node_instack(t_stack *stk, t_stack *node)
{
	if (!stk || !node)
		return (0);
	while (stk)
	{
		if (stk == node)
			return (1);
		stk = stk->prev;
	}
	return (0);
}

int	ft_node_detect(t_stack *hd, t_stack *beg, t_stack *end, t_stack *node)
{
	while (beg != end)
	{
		if (node == beg)
			return (1);
		beg = ft_stack_prev(hd, beg);
	}
	return (0);
}
