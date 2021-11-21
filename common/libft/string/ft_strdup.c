/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:59:15 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/20 03:53:13 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	i = 0;
	while (s1[i])
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!(dup))
		return (NULL);
	dup[i] = 0;
	while (--i >= 0)
		dup[i] = s1[i];
	return (dup);
}

/*
**	void	ft_putstr(char *str);
**	int	main(void)
**	{
**		char *str;
**
**		str = ft_strdup(0);
**	//	if (!())
**			return (0);
**		ft_putstr(str);
**		return (0);
**	}
*/
