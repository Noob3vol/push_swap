/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 23:13:29 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/16 00:12:03 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_part_check_h(t_stack *head, t_stack *pivot, t_stack *end)
{
	if (head == end)
		return (1);
	while (head != end)
	{
		if (head->nbr <= pivot->nbr)
			return (0);
		head = head->prev;
	}
	if (head->nbr <= pivot->nbr)
		return (0);
	return (1);
}

int	ft_part_check(t_stack **a, t_stack *beg, t_stack *end, t_stack *piv)
{
	while (beg != piv)
	{
		if (beg->nbr >= piv->nbr)
			return (0);
		beg = ft_stack_prev(*a, beg);
	}
	while (beg != end)
	{
		if (beg->nbr > piv->nbr)
			return (0);
		beg = ft_stack_prev(*a, beg);
	}
	return (1);
}

int	ft_check_pivot_parted(t_stack *head, t_stack *pivot, t_stack *end)
{
	while (head != pivot)
	{
		if (head->nbr > pivot->nbr)
			return (0);
		head = head->prev;
	}
	while (head != end)
	{
		if (head->nbr < pivot->nbr)
			return (0);
		head = head->prev;
	}
	if (head->nbr < pivot->nbr)
		return (0);
	return (1);
}
