/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_quickrecurse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:33:52 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/15 16:45:27 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_quickrec_l(t_stack **head, t_stack *beg, t_stack *end, t_stack *piv)
{
	t_list	*inst;
	t_list	*inst_added;

	inst = ft_stack_quicksort(head, beg, ft_stack_next(*head, piv));
	if (!inst)
		return (NULL);
	piv = ft_stack_prev(*head, piv);
	inst_added = ft_stack_quicksort(head, piv, end);
	if (!inst_added)
	{
		ft_lstclear(&inst, free);
		return (NULL);
	}
	ft_lstadd_back(&inst, inst_added);
	return (inst);
}

t_list	*ft_quickrec_h(t_stack **head, t_stack *beg, t_stack *end, t_stack *piv)
{
	t_list	*inst;
	t_list	*inst_added;

	inst = ft_stack_quicksort(head, ft_stack_prev(*head, piv), end);
	if (!inst)
		return (NULL);
	end = ft_stack_next(*head, piv);
	inst_added = ft_stack_quicksort(head, beg, end);
	if (!(inst_added))
	{
		ft_lstclear(&inst, free);
		return (NULL);
	}
	ft_lstadd_back(&inst, inst_added);
	return (inst);
}

t_list	*ft_quickrec(t_stack **head, t_stack *beg, t_stack *end, t_stack *piv)
{
	t_list	*inst;

	inst = NULL;
	if (ft_stack_rt_dist(*head, beg) < ft_stack_rt_dist(*head, piv))
	{
		inst = ft_quickrec_l(head, beg, end, piv);
		if (!inst)
		{
			return (NULL);
		}
	}
	else
	{
		inst = ft_quickrec_h(head, beg, end, piv);
		if (!inst)
			return (NULL);
	}
	return (inst);
}
