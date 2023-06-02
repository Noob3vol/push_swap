/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:41:49 by iguidado          #+#    #+#             */
/*   Updated: 2021/12/08 19:52:32 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_op_id	*ft_get_op_id(char *op)
{
	static t_op_id	op_table[] = {
	{"pa", ft_pa_wrap}, {"sa", ft_sa_wrap},
	{"ra", ft_ra_wrap}, {"rra", ft_rra_wrap},
	{"pb", ft_pb_wrap}, {"sb", ft_sb_wrap},
	{"rb", ft_rb_wrap}, {"rrb", ft_rrb_wrap},
	{"ss", ft_ss_wrap}, {"rr", ft_rr_wrap},
	{"rrr", ft_rrr_wrap}, {NULL, NULL}
	};
	int				i;

	i = 0;
	while (op_table[i].ft_op_wrap)
	{
		if (ft_strequ(op_table[i].id, op))
			return (&op_table[i]);
		i++;
	}
	return (NULL);
}

t_list	*ft_instadd_back(t_list *lst, char *inst)
{
	t_list	*new;
	char	*value;

	new = NULL;
	value = ft_strdup(inst);
	if (!(value))
	{
		ft_lstclear(&lst, free);
		return (NULL);
	}
	new = ft_lstnew(value);
	if (!(new))
	{
		free(value);
		ft_lstclear(&lst, free);
		return (NULL);
	}
	ft_lstadd_back(&lst, new);
	return (lst);
}

t_list	*ft_exec_op(t_list *insts, t_stack **a, t_stack **b, char *id)
{
	t_list	*new;
	t_op_id	*op_id;

	op_id = ft_get_op_id(id);
	if (!(op_id))
	{
		ft_lstclear(&insts, free);
		return (NULL);
	}
	op_id->ft_op_wrap(a, b);
	new = ft_instadd_back(insts, id);
	return (new);
}
