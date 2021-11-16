/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_wrap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:26:57 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/03 19:07:34 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_WRAP_H
# define STACK_WRAP_H
# include "stack.h"

void	ft_pa_wrap(t_stack **a, t_stack **b);
void	ft_sa_wrap(t_stack **a, t_stack **b);
void	ft_ra_wrap(t_stack **a, t_stack **b);
void	ft_rra_wrap(t_stack **a, t_stack **b);

void	ft_pb_wrap(t_stack **a, t_stack **b);
void	ft_sb_wrap(t_stack **a, t_stack **b);
void	ft_rb_wrap(t_stack **a, t_stack **b);
void	ft_rrb_wrap(t_stack **a, t_stack **b);

void	ft_ss_wrap(t_stack **a, t_stack **b);
void	ft_rr_wrap(t_stack **a, t_stack **b);
void	ft_rrr_wrap(t_stack **a, t_stack **b);

typedef void	(*t_stacks_op)(t_stack **, t_stack **);

typedef struct s_op_id
{
	char		*id;
	t_stacks_op	ft_op_wrap;
}		t_op_id;

#endif
