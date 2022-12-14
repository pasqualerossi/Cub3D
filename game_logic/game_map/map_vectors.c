/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:53:48 by prossi            #+#    #+#             */
/*   Updated: 2022/12/14 15:50:01 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Due to Norminette, the static function below had to be on 2 lines.

static void	set_values(double direction_x, double direction_y, double pla_x,
		double pla_y)
{
	data()->var.direction_x = direction_x;
	data()->var.direction_y = direction_y;
	data()->var.plane_x = pla_x;
	data()->var.plane_y = pla_y;
}

static void	init_vectors(int x, int y)
{
	data()->var.position_x = x + 0.5;
	data()->var.position_y = y + 0.5;
	if (data()->map[y][x] == 'N')
		set_values(0, -1, 0.66, 0);
	else if (data()->map[y][x] == 'S')
		set_values(0, 1, -0.66, 0);
	else if (data()->map[y][x] == 'E')
		set_values(1, 0, 0, 0.66);
	else if (data()->map[y][x] == 'W')
		set_values(-1, 0, 0, -0.66);
}

char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}

int	check_characters(void)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data()->map[i])
	{
		j = 0;
		while (data()->map[i][j])
		{
			if (!ft_strchr(" 10NSEW", data()->map[i][j]))
				return (0);
			if (data()->map[i][j] == 'N' || data()->map[i][j] == 'S' \
				|| data()->map[i][j] == 'E' || data()->map[i][j] == 'W')
			{
				init_vectors(j, i);
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}
