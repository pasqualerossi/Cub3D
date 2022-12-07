/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:50:28 by prossi            #+#    #+#             */
/*   Updated: 2022/12/07 18:18:11 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_start(char **buf, int fd, int *ret)
{
	buf[fd] = malloc(BUFFER_SIZE + 1);
	if (!buf[fd])
		return (-1);
	*ret = read(fd, buf[fd], BUFFER_SIZE);
	if (*ret < 0)
	{
		free(buf[fd]);
		return (-1);
	}
	buf[fd][*ret] = 0;
	return (0);
}

int	ft_in_while_a(char **buf, char *cat, char **tmp)
{
	int	i;

	i = 0;
	while ((*buf)[i])
	{
		cat[i] = (*buf)[i];
		i++;
	}
	i = 0;
	while ((*tmp)[i])
	{
		cat[i + ft_strlen(*buf)] = (*tmp)[i];
		i++;
	}
	cat[i + ft_strlen(*buf)] = 0;
	free(*tmp);
	free(*buf);
	*buf = cat;
	return (1);
}

int	ft_in_while(char **buf, int fd, int *ret)
{
	char	*tmp;
	char	*cat;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (-1);
	*ret = read(fd, tmp, BUFFER_SIZE);
	if (*ret < 0)
	{
		free(tmp);
		return (-1);
	}
	tmp[*ret] = 0;
	cat = malloc(ft_strlen(buf[fd]) + ft_strlen(tmp) + 1);
	if (!cat)
	{
		free(tmp);
		return (-1);
	}
	return ((ft_in_while_a(&(buf[fd]), cat, &tmp)));
}

int	ft_if_new_line(char **buf, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*buf)[i] != 10)
		i++;
	*line = ft_strdup(*buf);
	if (!*line)
		return (-1);
	(*line)[i] = 0;
	tmp = ft_strdup(&((*buf)[i + 1]));
	if (!tmp)
		return (-1);
	free((*buf));
	*buf = tmp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	*buf[OPEN_MAX];

	ret = BUFFER_SIZE;
	if (fd >= 0 && BUFFER_SIZE > 0 && fd < OPEN_MAX)
	{
		if (!buf[fd] && ft_start(buf, fd, &ret))
			return (-1);
		while (!ft_new_line(buf[fd]) && BUFFER_SIZE == ret)
			if (ft_in_while(buf, fd, &ret) == -1)
				return (-1);
		if (ft_new_line(buf[fd]))
			return (ft_if_new_line(&(buf[fd]), line));
		else
		{
			*line = ft_strdup(buf[fd]);
			if (!*line)
				return (-1);
			free(buf[fd]);
			buf[fd] = NULL;
			return (0);
		}
	}
	return (-1);
}
