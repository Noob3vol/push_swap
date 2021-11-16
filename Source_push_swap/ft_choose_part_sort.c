/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_part_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:16:27 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/10 16:03:43 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Work in progress : these function require optimized sub-stack sort
** Which is actually not the case, and are pretty hard to fit school norme
** Also including of quicksort mean i need to adapt my quicksort
** Else it is going to infinite call quicksort
*/
t_stack_part	ft_copy_part(t_stack *a, t_stack *begin, t_stack *end)
{
	t_stack_part	copy_part;
	t_stack			*node;
	t_stack			*copy;

	copy = ft_copy_stack(a);
	copy_part.head = &copy;
	copy_part.begin = NULL;
	copy_part.end = NULL;
	node = copy;
	while (!copy_part.begin && !copy_part.end)
	{
		if (node->nbr == begin->nbr)
			copy_part.begin = node;
		if (node->nbr == end->nbr)
			copy_part.begin = node;
		node = node->prev;
	}
	return (copy_part);
}

int	ft_try_part_sort(t_stack_part *prt_cpy, t_list **inst,
		t_list *(*ft_partsort)(t_stack **, t_stack *, t_stack *))
{
	t_list	*next_inst;

	next_inst = ft_partsort(prt_cpy->head, prt_cpy->begin, prt_cpy->end);
	if (!next_inst)
	{
		ft_lstclear(inst);
		return (0);
	}
	*inst = ft_select_inst(*inst, next_inst, prt_cpy->head);
	return (1);
}

int	ft_choose_part_sort(t_stack **a, t_stack **beg,
		t_stack **end, t_list **inst)
{
	t_stack_part	part_copy;
	t_list			*curr_inst;
	static t_list	*(*ft_part_sort[])(t_stack **, t_stack *, t_stack *) = {
		ft_part_sort_bubble,
		ft_part_sort_insrt,
		ft_part_sort_slct,
		ft_quicksort,
		NULL}
	int				i;

	part_copy = ft_copy_part(*a, *begin, *end);
	curr_inst = ft_part_sort[0](part_copy.head, part_copy.begin, part_copy.end);
	i = 0;
	return (1);
}
