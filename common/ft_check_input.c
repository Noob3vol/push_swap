/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:25:15 by iguidado          #+#    #+#             */
/*   Updated: 2021/12/09 21:48:59 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/*
** Nbr n'est jamais negatif donc nbr == INT_MIN trigger directement
** la condition rejetant les nombres superieur a INT_MAX
*/

int	predict_overflow(int nbr, char next_digit, int neg)
{
	if (!ft_isdigit(next_digit))
		return (0);
	if (nbr > (INT_MAX / 10))
		return (1);
	if (neg < 0)
	{
		if (nbr >= INT_MAX / 10 && next_digit == '9')
			return (1);
	}
	else
	{
		if (nbr == INT_MAX / 10 && next_digit >= '8')
			return (1);
	}
	return (0);
}

int	ft_check_value(char *value)
{
	int	nb;
	int	nb_of_value;

	nb = 0;
	nb_of_value = 0;
	if (!value)
		return (0);
	while (*value)
	{
		if (!(ft_strchr("0123456789 -+", *value)))
			return (0);
		value++;
	}
	return (nb_of_value);
}

int	ft_check_arg(int ac, char **av)
{
	while (ac--)
	{
		if (!ft_check_value(av[ac]))
			return (0);
	}
	return (1);
}
