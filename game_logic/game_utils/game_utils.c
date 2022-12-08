/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:39:39 by prossi            #+#    #+#             */
/*   Updated: 2022/12/08 14:31:25 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_array_length(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}

void	ft_free(char ***array)
{
	int	i;

	i = 0;
	if (!*array)
		return ;
	while ((*array)[i])
	{
		free((*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}

char	**ft_reallocation(char **pointer, int size)
{
	int		i;
	char	**new_pointer;

	i = 0;
	new_pointer = malloc(sizeof(char *) * size);
	if (!new_pointer)
		return (NULL);
	while (pointer[i])
	{
		new_pointer[i] = pointer[i];
		i++;
	}
	new_pointer[i] = NULL;
	new_pointer[i + 1] = NULL;
	free(pointer);
	return (new_pointer);
}

const char	*get_exit(const char *file)
{
	const char	*dot;

	dot = ft_strrchr(file, '.');
	if (!dot || dot == file)
		return ("");
	return (dot + 1);
}

unsigned long	rgb_to_hex(int red, int green, int blue)
{
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}
