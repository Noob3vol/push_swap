/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part_bubble_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:57:45 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/14 14:48:56 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_part_find_next_swap(t_stack *a, t_stack *beg, t_stack *end)
{
	t_stack	*curr;
	t_stack	*next;
	int		dist;

	dist = 0;
	next = NULL;
	while (!next)
	{
		curr = ft_stack_index(a, dist);
		if (ft_node_detect(a, beg, end, curr))
		{
			if (!(ft_node_ordered(a, curr)))
				return (curr);
		}
		curr = ft_stack_index_mod(a, -(dist + 1));
		if (ft_node_detect(a, beg, end, curr) && curr != end)
		{
			if (!(ft_node_ordered(a, curr)))
				return (curr);
		}
		dist++;
	}
	return (next);
}

t_list	*ft_part_swap_unordered(t_stack **head, t_stack **beg, t_stack **end)
{
	t_list	*inst;
	t_stack	*next;

	inst = NULL;
	next = ft_part_find_next_swap(*head, *beg, *end);
	if (!next)
		return (NULL);
	if (next != (*head))
	{
		inst = ft_crawl_stack(head, next, 'a');
		if (!inst)
			return (NULL);
	}
	if (next == (*beg))
		(*beg) = ft_stack_prev(*head, *beg);
	if (next->prev == (*end))
		(*end) = next;
	inst = ft_exec_op(inst, head, NULL, "sa");
	return (inst);
}

t_list	*ft_bubble_sort_max_part(t_stack **a, t_stack *beg, t_stack *end)
{
	t_list	*inst;
	t_list	*node;

	inst = NULL;
	while (!ft_stack_part_ordered(*a, beg, end))
	{
		node = ft_part_swap_unordered(a, &beg, &end);
		if (!(node))
		{
			ft_lstclear(&inst, free);
			return (NULL);
		}
		ft_lstadd_back(&inst, node);
	}
	return (inst);
}
