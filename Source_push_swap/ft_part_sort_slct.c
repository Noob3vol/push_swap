/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part_sort_slct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 23:14:30 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/17 02:51:47 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_qkslct_min(t_stack **a, t_stack **b, t_stack **beg, t_stack **end)
{
	t_list	*inst;
	t_stack	*min;

	min = ft_stkpart_min(*a, *beg, *end);
	inst = NULL;
	if (*beg == *end)
		*beg = NULL;
	else if (min == *beg)
		*beg = ft_stack_prev(*a, *beg);
	else if (min == *end)
		*end = ft_stack_next(*a, *end);
	if ((*a) != min)
	{
		inst = ft_crawl_stack(a, min, 'a');
		if (!(inst))
			return (NULL);
	}
	inst = ft_exec_op(inst, a, b, "pb");
	return (inst);
}

t_list	*ft_part_srt_slct(t_stack **a, t_stack *beg, t_stack *end)
{
	t_stack	*b;
	t_list	*inst;
	t_list	*node;

	b = NULL;
	inst = NULL;
	while (ft_node_detect(*a, beg, end, beg->prev)
		&& ft_stkprt_ordered(*a, beg, end))
	{
		node = ft_qkslct_min(a, &b, &beg, &end);
		if (!ft_instjoin(&inst, node))
			return (NULL);
	}
	if ((*a) != beg)
	{
		node = ft_crawl_stack(a, beg, 'a');
		if (!ft_instjoin(&inst, node))
			return (NULL);
	}
	inst = ft_stack_push_all_b(a, &b, inst);
	return (inst);
}
