/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:34:06 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/27 22:05:24 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	read_line(char **str, char **hist, int fd)
{
	int		bytes;
	int		i;
	char	buf[BUFF_SIZE + 1];

	i = -1;
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buf, BUFF_SIZE);
		buf[bytes] = '\0';
		*str = ft_strjoin_for_next_line(*str, buf);
		i = check_str(*str);
		if (i != -1)
		{
			*hist = *str;
			return (i);
		}
	}
	if (bytes < 0)
		return (-1);
	if (bytes == 0)
		return (-2);
	return (i);
}

int	return_line(char **line, char **str, int i, char **hist)
{
	size_t	j;

	j = ft_strlen(*str);
	*line = ft_strdup_for_next_line(*str, i);
	if (!line)
		return (-1);
	(*line)[i] = '\0';
	*str = ft_strdup_for_next_line((*str) + i + 1, j - i + 1);
	if (!str)
		return (-1);
	(*str)[j - i + 1] = '\0';
	*hist = *str;
	return (1);
}

void	i__2(char *str, char **line)
{
	if (str)
	{
		*line = ft_strdup_for_next_line(str, 0);
		free(str);
	}
	else
		*line = ft_strdup_for_next_line("", 1);
}

int	get_next_line(int fd, char **line)
{
	char	*str;
	char	*buff[100];
	int		i;

	str = NULL;
	if (!line || read(fd, str, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	str = buff[fd];
	i = check_str(str);
	if (i == -1)
		i = read_line(&str, line, fd);
	if (i == -2)
	{
		i__2(str, line);
		buff[fd] = NULL;
		return (0);
	}
	if (i < 0)
		return (-1);
	return (return_line(line, &str, i, &(buff[fd])));
}
