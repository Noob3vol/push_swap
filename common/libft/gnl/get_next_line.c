/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:52:41 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/19 15:40:48 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_mv_buff(char *buff)
{
	int	i;
	int	j;

	i = 0;
	while (i < BUFF_SIZE && buff[i] != '\n')
	{
		buff[i] = 0;
		i++;
	}
	if (i == BUFF_SIZE)
		return (0);
	buff[i++] = 0;
	j = 0;
	while (i + j < BUFF_SIZE)
	{
		buff[j] = buff[i + j];
		j++;
	}
	while (j < BUFF_SIZE)
		buff[j++] = 0;
	return (1);
}

char	*ft_buffdup(char *buff)
{
	int		i;
	char	*new;

	i = 0;
	while (i < BUFF_SIZE && buff[i] && buff[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (!(new))
		return (NULL);
	new[i] = 0;
	while (--i >= 0)
		new[i] = buff[i];
	return (new);
}

char	*ft_linecat(char *line, char *buff)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (i < BUFF_SIZE && buff[i] != '\n' && buff[i])
		i++;
	while (line[j] && line[j] != '\n')
		j++;
	new = (char *)malloc(sizeof(char) * (j + i + 1));
	if (!(new))
		return (NULL);
	new[i + j] = 0;
	while (--i >= 0)
		new[j + i] = buff[i];
	while (--j >= 0)
		new[j] = line[j];
	return (new);
}

int	ft_dump_buff(char **line, char *buff)
{
	char	*new_line;

	if (*line == NULL)
	{
		new_line = ft_buffdup(buff);
		if (!(new_line))
			return (-1);
	}
	else
	{
		new_line = ft_linecat(*line, buff);
		if (!(new_line))
			return (-1);
		free(*line);
	}
	*line = new_line;
	return (ft_mv_buff(buff));
}

int	get_next_line(int fd, char **line)
{
	static char	buff[BUFF_SIZE] = "";
	int			ret;

	if (!line)
		return (-1);
	*line = NULL;
	ret = ft_dump_buff(line, buff);
	while (!(ret))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if ((ret) < 1)
			return (ret);
		ret = ft_dump_buff(line, buff);
	}
	return (ret);
}
