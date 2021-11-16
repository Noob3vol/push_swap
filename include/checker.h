/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:25:51 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/03 18:25:55 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

int	ft_store_inst(t_list **inst);
int	ft_run_inst(t_stack **a, t_stack **b, t_list *inst);

#endif
