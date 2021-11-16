/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort_insrt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:41:29 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/02 13:26:06 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** return stack node immediatly lower than nbr or highest nbr stack in b
*/
t_stack	*ft_stack_lower(int nbr, t_stack *b)
{
	t_stack	*lower;
	t_stack	*highest;

	if (!b)
		return (NULL);
	lower = NULL;
	highest = b;
	while (b && b->nbr > nbr)
	{
		if (b->nbr > highest->nbr)
			highest = b;
		b = b->prev;
	}
	lower = b;
	while (b)
	{
		if (b->nbr > highest->nbr)
			highest = b;
		if (b->nbr < nbr && b->nbr > lower->nbr)
			lower = b;
		b = b->prev;
	}
	if (!lower)
		return (highest);
	return (lower);
}

t_list	*ft_srt_insrt_nbr(t_stack **a, t_stack **b, t_list *inst, t_stack *lwr)
{
	t_list	*node;
	int		dist;

	dist = ft_stack_rt_dist(*b, lwr);
	if (dist)
	{
		node = ft_crawl_dist(b, dist, 'b');
		if (!(node))
		{
			ft_lstclear(&inst, free);
			return (NULL);
		}
		ft_lstadd_back(&inst, node);
	}
	inst = ft_exec_op(inst, a, b, "pb");
	if (!(inst))
		return (NULL);
	return (inst);
}

t_list	*ft_stack_srt_insrt_reorganize(t_stack **a, t_stack **b, t_list *inst)
{
	t_stack	*highest;
	t_list	*inst_node;

	highest = ft_stack_highest(*b);
	if ((*b) != highest)
	{
		inst_node = ft_crawl_stack(b, highest, 'b');
		if (!(inst_node))
		{
			ft_lstclear(&inst, free);
			return (NULL);
		}
		ft_lstadd_back(&inst, inst_node);
	}
	inst = ft_stack_push_all_b(a, b, inst);
	if (!(inst))
		return (NULL);
	return (inst);
}

t_list	*ft_stack_srt_insrt(t_stack **a)
{
	t_stack	*b;
	t_stack	*next;
	t_list	*inst;

	b = NULL;
	inst = ft_exec_op(NULL, a, &b, "pb");
	while (*a)
	{
		next = ft_stack_lower((*a)->nbr, b);
		inst = ft_srt_insrt_nbr(a, &b, inst, next);
		if (!(inst))
			return (NULL);
	}
	inst = ft_stack_srt_insrt_reorganize(a, &b, inst);
	if (!(inst))
		return (NULL);
	return (inst);
}
