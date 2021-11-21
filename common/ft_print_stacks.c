/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:42:21 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/17 16:59:45 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	ft_print_footer(void)
{
	ft_putchar('\t');
	ft_putchar('a');
	ft_putchar('\t');
	ft_putchar('b');
	ft_putchar('\n');
}

static int	ft_condition_printing(t_stack *stack, int max_depth)
{
	int	stack_depth;

	stack_depth = ft_stack_depth(stack);
	ft_putchar('\t');
	if (stack_depth > max_depth && stack)
	{
		ft_putnbr(stack->nbr);
		return (1);
	}
	ft_putchar(' ');
	return (0);
}

int	ft_max_depth_stack(t_stack *a, t_stack *b)
{
	int	depth_a;
	int	depth_b;

	depth_a = ft_stack_depth(a);
	depth_b = ft_stack_depth(b);
	if (depth_a > depth_b)
		return (depth_a);
	return (depth_b);
}

void	ft_print_stacks(t_stack *a, t_stack *b)
{
	int	depth_max;

	depth_max = ft_max_depth_stack(a, b);
	ft_putchar('\n');
	ft_putchar('\n');
	while (depth_max--)
	{
		if (ft_condition_printing(a, depth_max))
			a = a->prev;
		if (ft_condition_printing(b, depth_max))
			b = b->prev;
		ft_putchar('\n');
	}
	ft_print_footer();
}
