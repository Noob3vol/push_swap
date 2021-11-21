/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:40:22 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/19 15:33:03 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include "stack_wrap.h"
# include "libft.h"
# include <limits.h>

/*
** Print_stacks include static function as helper
*/
void		ft_print_stacks(t_stack *a, t_stack *b);
t_stacks_op	ft_get_op(char *op);

/*
** ft_inst_exec : function executing stack instruction
*/
t_op_id		*ft_get_op_id(char *op);
t_list		*ft_instadd_back(t_list *lst, char *inst);
t_list		*ft_exec_op(t_list *insts, t_stack **a, t_stack **b, char *id);

/*
** ft_check_arg : Checking argument validity in ft_store_arg
*/
int			predict_overflow(int nbr, char next_digit, int neg);
int			ft_check_value(char *value);
int			ft_check_arg(int ac, char **av);

/*
** ft_store_stack : Store argument as stack
*/
int			ft_atoi_crawl(char **str, int *origin_nbr);
int			ft_stackaddnbr_back(t_stack **stacks, int nbr);
t_stack		*ft_store_stack(int ac, char **av);

/*
** ft_inst_exec : function executing stack instruction
*/
t_op_id		*ft_get_op_id(char *op);
t_list		*ft_instadd_back(t_list *lst, char *inst);
t_list		*ft_exec_op(t_list *insts, t_stack **a, t_stack **b, char *id);

/*
** ft_check_win
*/
int			ft_check_win(t_stack *a, t_stack *b);

#endif
