/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_adv_inst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:18:20 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/14 15:07:56 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_rotate_dist(t_stack **stack, int distance, char stack_id)
{
	t_list	*lst;
	t_list	*new;

	lst = NULL;
	new = NULL;
	while (distance > 0)
	{
		if (stack_id == 'a')
		{
			lst = ft_exec_op(lst, stack, NULL, "ra");
			if (!(lst))
				return (NULL);
		}
		else if (stack_id == 'b')
		{
			lst = ft_exec_op(lst, NULL, stack, "rb");
			if (!(lst))
				return (NULL);
		}
		distance--;
	}
	return (lst);
}

t_list	*ft_rrotate_dist(t_stack **stack, int distance, char stack_id)
{
	t_list	*lst;

	lst = NULL;
	while (distance < 0)
	{
		if (stack_id == 'a')
		{
			lst = ft_exec_op(lst, stack, NULL, "rra");
			if (!(lst))
				return (NULL);
		}
		else if (stack_id == 'b')
		{
			lst = ft_exec_op(lst, NULL, stack, "rrb");
			if (!(lst))
				return (NULL);
		}
		distance++;
	}
	return (lst);
}

t_list	*ft_crawl_dist(t_stack **stack, int distance, char stack_id)
{
	t_list	*lst;
	t_list	*new;

	lst = NULL;
	new = NULL;
	if (distance < 0)
	{
		new = ft_rrotate_dist(stack, distance, stack_id);
		if (!(new))
			return (NULL);
		ft_lstadd_back(&lst, new);
	}
	if (distance > 0)
	{
		new = ft_rotate_dist(stack, distance, stack_id);
		if (!(new))
			return (NULL);
		ft_lstadd_back(&lst, new);
	}
	return (lst);
}

t_list	*ft_crawl_stack(t_stack **head, t_stack *target, char stack_id)
{
	int		rt_dist;
	t_list	*inst;

	rt_dist = 0;
	inst = NULL;
	if (*head == target)
		return (ft_instadd_back(NULL, ""));
	rt_dist = ft_stack_rt_dist(*head, target);
	return (ft_crawl_dist(head, rt_dist, stack_id));
}

t_list	*ft_stack_push_all_b(t_stack **a, t_stack **b, t_list *inst)
{
	while (*b)
	{
		inst = ft_exec_op(inst, a, b, "pa");
		if (!(inst))
			return (NULL);
	}
	return (inst);
}
