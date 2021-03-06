/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:13:00 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/20 18:10:14 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_fusion;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str_fusion = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!(str_fusion))
		return (NULL);
	while (j >= 0)
	{
		str_fusion[i + j] = s2[j];
		j--;
	}
	while (--i >= 0)
		str_fusion[i] = s1[i];
	return (str_fusion);
}

/*
**	#include "libft.h"
**	int	main(void)
**	{
**		char *str;
**	
**		str = ft_strjoin("hello", " world !");
**		ft_putstr(str);
**		free(str);
**	    return (0);
**	}
*/
