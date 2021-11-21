/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort_slct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:46:50 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/20 20:02:40 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_rtt_to_min(t_stack **a, t_list **inst)
{
	t_list	*node;
	t_stack	*min;
	int		dist_to_min;

	if (!inst)
		return (0);
	min = ft_stack_min(*a);
	node = NULL;
	dist_to_min = ft_stack_rt_dist(*a, min);
	if ((dist_to_min))
	{
		node = ft_crawl_dist(a, dist_to_min, 'a');
		if (!(node))
		{
			ft_lstclear(inst, free);
			return (0);
		}
		ft_lstadd_back(inst, node);
	}
	return (1);
}

t_list	*ft_stack_srt_slct_min(t_stack **a, t_stack **b, t_list *inst)
{
	if (!(ft_stack_rtt_to_min(a, &inst)))
		return (NULL);
	inst = ft_exec_op(inst, a, b, "pb");
	return (inst);
}

int	ft_stack_slctsrt_arrange(t_stack **a, t_stack **b, t_list **inst)
{
	t_list	*inst_added;

	if (!ft_stack_ordered(*a))
	{
		inst_added = ft_stack_sort_bubble_max_a(a);
		if (!inst_added)
		{
			ft_lstclear(inst, free);
			return (0);
		}
		ft_lstadd_back(inst, inst_added);
	}
	if (!(ft_stack_rtt_to_min(a, inst)))
		return (0);
	*inst = ft_stack_push_all_b(a, b, *inst);
	if (!(*inst))
		return (0);
	return (1);
}

t_list	*ft_stack_sort_slct(t_stack **a)
{
	t_list	*list;
	t_stack	*b;

	b = NULL;
	list = NULL;
	while (ft_stack_depth(*a) > 3)
	{
		list = ft_stack_srt_slct_min(a, &b, list);
		if (!(list))
			return (NULL);
	}
	if (!ft_stack_slctsrt_arrange(a, &b, &list))
		return (NULL);
	return (list);
}
