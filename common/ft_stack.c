/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:42:44 by iguidado          #+#    #+#             */
/*   Updated: 2021/12/13 21:21:35 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*ft_init_stack(int value, t_stack *prev)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!(new))
		return (NULL);
	new->prev = prev;
	new->nbr = value;
	return (new);
}

int	ft_free_stack(t_stack **stack)
{
	t_stack	*prev;

	while (*stack)
	{
		prev = (*stack)->prev;
		free(*stack);
		*stack = prev;
	}
	return (0);
}
