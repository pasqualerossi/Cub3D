/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_colours.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:49:48 by prossi            #+#    #+#             */
/*   Updated: 2022/10/28 12:50:11 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*validate_rgb(char **arr)
{
	int	i;
	int	*rgb;

	i = 0;
	rgb = malloc(sizeof(int) * 4);
	if (!rgb)
		return (NULL);
	while (arr[i])
	{
		rgb[i] = ft_atoi(arr[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (NULL);
		i++;
	}
	rgb[i] = 0;
	return (rgb);
}

void	convert_colors(int *rgb, int i)
{
	unsigned long	tmp;

	if (i == 0)
	{
		tmp = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
		data()->floor = tmp;
	}
	if (i == 1)
	{
		tmp = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
		data()->ceilling = tmp;
	}
}

int	init_colors(void)
{
	int				i;
	char			**tmp;
	int				*rgb;

	i = 0;
	while (data()->rgb[i])
	{
		tmp = ft_split(data()->rgb[i], ',');
		if (!tmp)
			return (1);
		rgb = validate_rgb(tmp);
		if (!rgb)
		{
			free(rgb);
			return (1);
		}
		convert_colors(rgb, i);
		ft_free(&tmp);
		free(rgb);
		i++;
	}
	return (0);
}