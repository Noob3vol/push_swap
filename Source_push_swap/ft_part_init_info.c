/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part_init_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:17:12 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/12 17:38:43 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function to init struct which contain all partition information
*/

t_stkpart	*ft_stkpart_info(t_stack *a, t_stack **debut, t_stack **end)
{
	t_stkpart	*new;

	if (!a)
		return (NULL);
	new = (t_stkpart *)malloc(sizeof(t_stkpart));
	new->debut = debut;
	new->end = end;
	new->max = ft_stkpart_max(a, *debut, *end);
	new->min = ft_stkpart_min(a, *debut, *end);
	new->pivot = ft_stkpart_choose_pivot(*debut, *end);
	new->next_debut = NULL;
	new->next_end = NULL;
	return (new);
}

void	ft_print_stkpart_info(t_stack *a, t_stack *b, t_stkpart *info)
{
	ft_print_value("debut = ", (*(info->debut))->nbr);
	ft_print_value("end = ", (*(info->end))->nbr);
	ft_print_value("pivot = ", ((info->pivot))->nbr);
	ft_print_stacks(a, b);
	ft_putstr("new begin = ");
	if (info->next_debut)
		ft_putnbr(info->next_debut->nbr);
	else
		ft_putstr("NULL");
	ft_putchar('\n');
	ft_putstr("new end = ");
	if (info->next_end)
		ft_putnbr(info->next_end->nbr);
	else
		ft_putstr("NULL");
	ft_putchar('\n');
}
