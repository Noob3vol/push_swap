/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 00:18:11 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/08 00:18:16 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_instjoin(t_list **inst, t_list *inst_added)
{
	if (!inst_added)
	{
		ft_lstclear(inst, free);
		return (0);
	}
	ft_lstadd_back(inst, inst_added);
	return (1);
}
