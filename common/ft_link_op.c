/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:41:54 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/17 16:42:14 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_stacks_op	ft_get_op(char *op)
{
	int				i;
	static t_op_id	op_table[] =
	{
		{"pa", ft_pa_wrap}, {"sa", ft_sa_wrap},
		{"ra", ft_ra_wrap}, {"rra", ft_rra_wrap},
		{"pb", ft_pb_wrap}, {"sb", ft_sb_wrap},
		{"rb", ft_rb_wrap}, {"rrb", ft_rrb_wrap},
		{"ss", ft_ss_wrap}, {"rr", ft_rr_wrap},
		{"rrr", ft_rrr_wrap}, {NULL, NULL}
	};

	i = 0;
	while (op_table[i].ft_op_wrap)
	{
		if (ft_strequ(op_table[i].id, op))
			return (op_table[i].ft_op_wrap);
		i++;
	}
	return (NULL);
}
