/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:11:49 by prossi            #+#    #+#             */
/*   Updated: 2022/12/07 19:15:23 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_exit_parse(char *s, int fd)
{
	if (fd < 0)
		close(fd);
	write(2, s, ft_strlen(s));
	ft_free(&data()->xpm);
	ft_free(&data()->rgb);
	ft_free(&data()->map);
	exit(1);
}

int	parse(char *file)
{
	int	fd;

	if (ft_strncmp(get_exit(file), "cub", 4) != 0)
		ft_exit_parse("Error\nInvalid extension\n", -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit_parse("Error\nCannot open the map\n", fd);
	if (parse_info(fd) == 1)
		ft_exit_parse("Error\nInvalid information\n", fd);
	if (parse_map(fd) == 1)
		ft_exit_parse("Error\nInvalid map\n", fd);
	close(fd);
	return (0);
}
