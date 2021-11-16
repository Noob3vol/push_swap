/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:53:28 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/02 11:53:29 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_len(t_stack *stk)
{
	int	len;

	len = 0;
	while (stk)
	{
		len++;
		stk = stk->prev;
	}
	return (len);
}

t_stack	*ft_stack_index(t_stack *stk, int index)
{
	while (stk && index > 0)
	{
		stk = stk->prev;
		index--;
	}
	return (stk);
}

t_stack	*ft_stack_index_mod(t_stack *stk, int index)
{
	int	stk_len;

	if (index < 0)
	{
		stk_len = ft_stack_len(stk);
		if (index < -stk_len)
			return (NULL);
		index = stk_len + index;
	}
	return (ft_stack_index(stk, index));
}
