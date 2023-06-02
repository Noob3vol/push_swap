/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:27:37 by iguidado          #+#    #+#             */
/*   Updated: 2021/12/13 21:15:54 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "libft.h"
#include <limits.h>

int	ft_atoi_crawl(char **str, int *origin_nbr)
{
	int	neg;
	int	nbr;

	neg = 1;
	nbr = 0;
	while (**str == ' ')
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			neg *= -1;
		(*str)++;
	}
	if (!ft_isdigit(**str))
		return (0);
	while (**str >= '0' && **str <= '9')
	{
		if (predict_overflow(nbr, **str, neg))
			return (0);
		nbr *= 10;
		nbr += **str - '0';
		(*str)++;
	}
	*origin_nbr = nbr * neg;
	return (1);
}

int	ft_stackaddnbr_back(t_stack **stacks, int nbr)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
	{
		ft_free_stack(stacks);
		return (0);
	}
	node->nbr = nbr;
	node->prev = NULL;
	if (!*stacks)
		*stacks = node;
	else
		ft_stackadd_back(stacks, node);
	return (1);
}

t_stack	*ft_store_stack(int ac, char **av)
{
	t_stack	*new;
	t_stack	*head;
	int		nbr;

	head = NULL;
	while (ac--)
	{
		new = NULL;
		if (!*(av[ac]))
			return (NULL);
		while (*(av[ac]))
		{
			if ((!ft_atoi_crawl(&av[ac], &nbr))
				|| !(ft_stackaddnbr_back(&new, nbr)))
			{
				ft_free_stack(&head);
				return (NULL);
			}
			while (*(av[ac]) == ' ')
				av[ac]++;
		}
		ft_stackadd_back(&new, head);
		head = new;
	}
	return (head);
}
