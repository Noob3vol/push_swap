/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:31:07 by iguidado          #+#    #+#             */
/*   Updated: 2021/09/23 17:52:46 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{

	t_list *head;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	if (alst)
	{
		head = *alst;
		while ((*alst)->next)
		{
			*alst = (*alst)->next;
		}
		(*alst)->next = new;
		*alst = head;
	}
}
