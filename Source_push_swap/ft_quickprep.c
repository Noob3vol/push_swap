/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quickprep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:33:27 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/19 14:54:19 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_part(t_stack *head, t_stack *begin, t_stack *end)
{
	while (begin != end)
	{
		ft_print_value("", begin->nbr);
		begin = ft_stack_prev(head, begin);
	}
}

/*
** Quickprep : to avoid useless operation we check if sub-stack
** is sorted or too small (meaning we don't quickpart it anymore)
** 
** we also crawl/travel to part top stack-node if needed
*/
int	ft_mng_excep(t_stack **head, t_stack *beg, t_stack *end, t_list **inst)
{
	int			part_len;
	t_list		*inst_added;

	part_len = ft_stack_ruler(*head, beg, end);
	if (part_len == 1)
	{
		if (!ft_node_ordered(*head, beg))
			(*inst) = ft_exec_op((*inst), head, NULL, "sa");
		return (1);
	}
	if (part_len <= 3)
	{
		(inst_added) = ft_bubble_sort_max_part(head, beg, end);
		ft_lstadd_back(inst, inst_added);
		return (1);
	}
	return (0);
}

int	ft_quickprep(t_stack **head, t_stack *beg, t_stack *end, t_list **inst)
{
	if (beg == end || ft_stkprt_ordered(*head, beg, end))
	{
		if (!(*inst))
			(*inst) = ft_instadd_back(*inst, "");
		return (0);
	}
	if ((*head) != beg)
	{
		(*inst) = ft_crawl_stack(head, beg, 'a');
		if (!*(inst))
			return (0);
	}
	if (ft_mng_excep(head, beg, end, inst))
	{
		if (!(*inst))
			(*inst) = ft_instadd_back(*inst, "");
		return (0);
	}
	return (1);
}

/*
**	int	ft_mng_excep(t_stack **head, t_stack *beg, t_stack *end, t_list **inst)
**	{
**		t_list	*node;
**
**		if (part_len <= 4)
**		{
**			node = ft_part_srt_insrt(head, end);
**			if (!node)
**				ft_lstclear(inst, free);
**			ft_lstadd_back(inst, node);
**			return (1);
**		}
**	}
*/
