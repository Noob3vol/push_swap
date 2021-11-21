/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_quicksort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 02:10:50 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/17 02:10:51 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_quickpart_rec(t_stack **head, t_stkpart *nfo, t_list **inst)
{
	t_list		*inst_added;

	if (!ft_check_pivot_parted(*head, nfo->pivot, *(nfo->end)))
	{
		if (!ft_quickpart(head, nfo, inst))
			return (0);
	}
	if (nfo->next_debut)
		*(nfo->debut) = nfo->next_debut;
	if (nfo->next_end)
		*(nfo->end) = nfo->next_end;
	inst_added = ft_quickrec(head, *(nfo->debut), *(nfo->end), nfo->pivot);
	if (!(inst_added))
	{
		ft_lstclear(inst, free);
		return (0);
	}
	ft_lstadd_back(inst, inst_added);
	free(nfo);
	return (1);
}

t_list	*ft_stack_quicksort(t_stack **head, t_stack *begin, t_stack *end)
{
	t_list			*inst;
	t_stkpart		*part_nfo;

	inst = NULL;
	if (!ft_quickprep(head, begin, end, &inst))
	{
		return (inst);
	}
	part_nfo = ft_stkpart_info(*head, &begin, &end);
	if (!ft_quickpart_rec(head, part_nfo, &inst))
		return (NULL);
	return (inst);
}

t_list	*ft_launch_quicksort(t_stack **a)
{
	t_list	*inst;
	t_list	*inst_added;

	inst = ft_stack_quicksort(a, *a, ft_stack_last_node(*a));
	inst_added = ft_crawl_stack(a, ft_stack_min(*a), 'a');
	ft_lstadd_back(&inst, inst_added);
	return (inst);
}
