/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:41:33 by iguidado          #+#    #+#             */
/*   Updated: 2021/12/13 21:37:26 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*prev;
}				t_stack;

/*
** ft_stack : Basic stack creation and destruction function
*/

t_stack	*ft_init_stack(int value, t_stack *prev);
int		ft_free_stack(t_stack **stack);
void	ft_stackadd_back(t_stack **stack, t_stack *node);

/*
** ft_stack_utils : utility function
*/

int		ft_stack_issort(t_stack *a);
int		ft_push_value(int value, t_stack *stack);
t_stack	*ft_copy_stack(t_stack *stack);

/*
** ft_stack_ruler : to mesure distance
*/

int		ft_stack_depth(t_stack *stack);
int		ft_stack_ruler(t_stack *head, t_stack *beg, t_stack *end);
int		ft_stack_rt_dist(t_stack *head, t_stack *addr);

/*
** ft_stack_op : primitive operation on stack
*/

void	ft_push_stack(t_stack **to_stack, t_stack **from_stack);
void	ft_rotate_stack(t_stack **stack);
void	ft_rev_rotate_stack(t_stack **stack);
void	ft_swap_stack(t_stack **stack);

#endif
