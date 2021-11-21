/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_wrapper_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:44:01 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/17 16:44:05 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_pa_wrap(t_stack **a, t_stack **b)
{
	ft_push_stack(a, b);
}

void	ft_sa_wrap(t_stack **a, t_stack **b)
{
	(void)b;
	ft_swap_stack(a);
}

void	ft_ra_wrap(t_stack **a, t_stack **b)
{
	(void)b;
	ft_rotate_stack(a);
}

void	ft_rra_wrap(t_stack **a, t_stack **b)
{
	(void)b;
	ft_rev_rotate_stack(a);
}
