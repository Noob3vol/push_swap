/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part_sort_insrt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:06:32 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/04 20:06:34 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_part_srt_insrt(t_stack **a, t_stack *end)
{
	t_list	*inst;
	t_stack	*b;
	t_stack	*next;

	b = NULL;
	inst = ft_exec_op(NULL, a, &b, "pb");
	while (*a != end)
	{
		next = ft_stack_lower((*a)->nbr, b);
		inst = ft_srt_insrt_nbr(a, &b, inst, next);
		if (!(inst))
			return (NULL);
	}
	next = ft_stack_lower((*a)->nbr, b);
	inst = ft_srt_insrt_nbr(a, &b, inst, next);
	if (!(inst))
		return (NULL);
	inst = ft_stack_srt_insrt_reorganize(a, &b, inst);
	if (!(inst))
		return (NULL);
	return (inst);
}
