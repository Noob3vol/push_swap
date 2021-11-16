/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part_gather_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:15:15 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/10 14:57:14 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Pick pivot can be used with stack on any state, 
** it's an alternative to ft_choose_pivot underneath
*/

t_stack	*ft_stkpart_pick_pivot(t_stack *a, t_stack *beg)
{
	t_stack	*beg_prev;
	t_stack	*beg_prev_2;

	beg_prev = ft_stack_prev(a, beg);
	beg_prev_2 = ft_stack_prev(a, beg_prev);
	if ((beg->nbr > beg_prev->nbr) ^ (beg->nbr > beg_prev_2->nbr))
		return (beg);
	if ((beg_prev->nbr > beg_prev_2->nbr) ^ (beg_prev->nbr > beg->nbr))
		return (beg_prev);
	return (beg_prev_2);
}

/*
** ft_stkpart_choose_pivot choose best pivot by sorting part in tab struct 
** and picking middle value
*/

t_stack	*ft_stkpart_choose_pivot(t_stack *begin, t_stack *end)
{
	int	*stack_tab;
	int	stack_dist;
	int	pivot;

	stack_dist = ft_stack_ruler(NULL, begin, end);
	stack_tab = ft_stack_to_tab(begin, stack_dist + 1);
	if (!stack_tab)
		return (NULL);
	stack_tab = ft_quicksort(stack_tab, 0, stack_dist);
	pivot = stack_tab[stack_dist / 2];
	while (begin->nbr != pivot)
		begin = begin->prev;
	free(stack_tab);
	return (begin);
}

t_stack	*ft_stkpart_min(t_stack *head, t_stack *beg, t_stack *end)
{
	t_stack	*min;

	min = beg;
	while (beg != end)
	{
		beg = ft_stack_prev(head, beg);
		if (beg->nbr < min->nbr)
			min = beg;
	}
	return (min);
}

t_stack	*ft_stkpart_max(t_stack *head, t_stack *begin, t_stack *end)
{
	t_stack	*max;

	max = begin;
	while (begin != end)
	{
		begin = ft_stack_prev(head, begin);
		if (begin->nbr > max->nbr)
			max = begin;
	}
	return (max);
}
