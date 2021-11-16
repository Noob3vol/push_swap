/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:06:55 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/01 17:06:56 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_inst(void *inst)
{
	char	*inst_tr;

	inst_tr = (char *)inst;
	if (*inst_tr != '\0')
	{
		ft_putstr(inst_tr);
		ft_putchar('\n');
	}
}

void	ft_print_insts(t_list *inst)
{
	while (inst)
	{
		ft_print_inst(inst->content);
		inst = inst->next;
	}
}

t_list	*ft_trim_inst(t_list *inst)
{
	t_list	*tmp;
	t_list	*head;

	head = NULL;
	while (!head)
	{
		if (*((char *)inst->content))
			head = inst;
		else
		{
			tmp = inst;
			inst = inst->next;
			ft_lstdelone(tmp, free);
		}
	}
	return (head);
}

t_list	*ft_adapt_inst(t_list *inst)
{
	t_list	*tmp;
	t_list	*head;

	head = ft_trim_inst(inst);
	inst = head;
	while (inst->next)
	{
		if (*((char *)inst->next->content))
			inst = inst->next;
		else
		{
			tmp = inst->next;
			inst->next = inst->next->next;
			ft_lstdelone(tmp, free);
		}
	}
	return (head);
}
