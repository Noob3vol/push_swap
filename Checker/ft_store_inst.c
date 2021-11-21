/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_inst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:35:52 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/21 14:20:26 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	ft_store_line(t_list **inst, char *line)
{
	t_list	*new;

	new = ft_lstnew(line);
	if (!(new))
	{
		free(line);
		ft_lstclear(inst, free);
		return (0);
	}
	ft_lstadd_back(inst, new);
	return (1);
}

int	ft_store_inst(t_list **inst)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!ft_store_line(inst, line))
			return (0);
	}
	if (!(*line))
		free(line);
	else
	{
		if (!ft_store_line(inst, line))
			return (0);
	}
	return (1);
}

int	ft_run_inst(t_stack **a, t_stack **b, t_list *inst)
{
	t_stacks_op	op;

	while (inst)
	{
		op = ft_get_op(inst->content);
		if (!(op))
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		op(a, b);
		inst = inst->next;
	}
	return (1);
}
