/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_wrapper_all.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:44:08 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/17 16:44:12 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_ss_wrap(t_stack **a, t_stack **b)
{
	ft_swap_stack(a);
	ft_swap_stack(b);
}

void	ft_rr_wrap(t_stack **a, t_stack **b)
{
	ft_rotate_stack(a);
	ft_rotate_stack(b);
}

void	ft_rrr_wrap(t_stack **a, t_stack **b)
{
	ft_rev_rotate_stack(a);
	ft_rev_rotate_stack(b);
}
