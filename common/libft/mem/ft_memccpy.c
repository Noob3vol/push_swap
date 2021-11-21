/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:51:24 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/20 18:25:34 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	while (n)
	{
		if (*src_tmp == (unsigned char)c)
		{
			*dest_tmp = (unsigned char)c;
			return ((void *)++dest_tmp);
		}
		*dest_tmp = *src_tmp;
		dest_tmp++;
		src_tmp++;
		n--;
	}
	return (NULL);
}
/*	
**	int	main(void)
**	{
**		char hello[] = "HELLO";
**		char world[5] = "";
**	
**		ft_memccpy(world, hello, 'B', 10);
**		write(1, world, 5);
**		return (0);
**	}
*/
