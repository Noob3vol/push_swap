/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:51:07 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/02 11:51:16 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function will infinite loop used in sorted stack
*/
t_stack	*ft_find_next_swap(t_stack *a)
{
	t_stack	*curr;
	t_stack	*next;
	int		dist;

	dist = 0;
	next = NULL;
	while (!next)
	{
		curr = ft_stack_index(a, dist);
		if (!(ft_node_ordered(a, curr)))
		{
			return (curr);
		}
		curr = ft_stack_index_mod(a, -(dist + 1));
		if (!(ft_node_ordered(a, curr)))
		{
			return (curr);
		}
		dist++;
	}
	return (next);
}

/*
** Function will infinite loop used in sorted stack
*/
t_list	*ft_swap_next_unordered(t_stack **stk, int s_id)
{
	t_list	*inst;

	inst = NULL;
	if (ft_node_ordered(*stk, *stk))
	{
		inst = ft_crawl_stack(stk, ft_find_next_swap(*stk), s_id);
		if (!(inst))
			return (NULL);
	}
	if (s_id == 'a')
		inst = ft_exec_op(inst, stk, NULL, "sa");
	else if (s_id == 'b')
		inst = ft_exec_op(inst, stk, NULL, "sb");
	return (inst);
}

t_list	*ft_stack_sort_bubble_max_a(t_stack **a)
{
	t_list	*inst;
	t_list	*inst_added;
	t_stack	*min;

	inst = NULL;
	while (!ft_stack_ordered(*a))
	{
		inst_added = ft_swap_next_unordered(a, 'a');
		if (!(inst_added))
		{
			ft_lstclear(&inst, free);
			return (NULL);
		}
		ft_lstadd_back(&inst, inst_added);
	}
	min = ft_stack_min(*a);
	if ((*a) != min)
	{
		inst_added = ft_crawl_stack(a, min, 'a');
		ft_lstadd_back(&inst, inst_added);
	}
	return (inst);
}
