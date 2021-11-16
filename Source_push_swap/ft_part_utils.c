/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:24:52 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/01 17:24:54 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_part(t_stack *stk, t_stack *beg, t_stack *end)
{
	ft_putstr("printing part ");
	ft_putnbr(beg->nbr);
	ft_putstr("\t->\t");
	ft_putnbr(end->nbr);
	ft_putchar('\n');
	while (beg != end)
	{
		ft_putnbr(beg->nbr);
		ft_putchar('\n');
		beg = ft_stack_prev(stk, beg);
	}
	ft_putnbr(beg->nbr);
	ft_putchar('\n');
}
