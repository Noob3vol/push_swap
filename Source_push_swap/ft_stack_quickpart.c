/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_quickpart.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:54:37 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/19 14:54:39 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Partitionning system : a lot of optimization can be done at this level
 */

int	ft_quickpiv(t_stack **a, t_stack **b, t_stkpart *info, t_list **inst)
{
	if ((*a)->nbr >= info->pivot->nbr && (*a) != *(info->end))
	{
		*inst = ft_exec_op(*inst, a, b, "pb");
		if (!(*inst))
			return (0);
	}
	else
	{
		if (!info->next_debut)
			info->next_debut = (*a);
		*inst = ft_exec_op(*inst, a, b, "ra");
		if (!(*inst))
			return (0);
	}
	return (1);
}

int	ft_quickpivot_l(t_stack **a, t_stack **b, t_stkpart *nfo, t_list **inst)
{
	while ((*a) != *(nfo->end) && (*b) != nfo->pivot)
	{
		if (!ft_quickpiv(a, b, nfo, inst))
			return (0);
	}
	if ((*b) == nfo->pivot)
	{
		(*inst) = ft_exec_op((*inst), a, b, "rb");
		if (!*inst)
			return (0);
	}
	return (1);
}

int	ft_quickpivot_h(t_stack **a, t_stack **b, t_stkpart *nfo, t_list **inst)
{
	while (!ft_part_check_h(*a, nfo->pivot, *(nfo->end)))
	{
		if (!(ft_quickpiv(a, b, nfo, inst)))
			return (0);
	}
	if ((*a) == *(nfo->end) && (*a)->nbr <= nfo->pivot->nbr)
	{
		(nfo->next_end) = *(b);
		*inst = ft_exec_op(*inst, a, b, "ra");
		if (!(inst))
			return (0);
	}
	return (1);
}

int	ft_quickpart(t_stack **a, t_stkpart *part_nfo, t_list **inst)
{
	t_stack		*b;

	b = NULL;
	if (!ft_quickpivot_l(a, &b, part_nfo, inst))
		return (0);
	if (!ft_quickpivot_h(a, &b, part_nfo, inst))
		return (0);
	*(inst) = ft_stack_push_all_b(a, &b, *(inst));
	if (!inst)
		return (0);
	return (1);
}
