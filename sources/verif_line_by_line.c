/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_line_by_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:16:57 by aclement          #+#    #+#             */
/*   Updated: 2023/10/23 09:16:08 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_verif_bad_elem(t_env *data)
{
	int	i;
	int	size_bef_map;

	size_bef_map = data->size - data->map.size;
	i = 0;
	while (i <= size_bef_map)
	{
		if (data->tab[i][0] == 'S' && data->tab[i][1] == ' ')
			return (printf("Error\nthere is a bad elem\n"), 0);
		if (data->tab[i][0] == 'N' && data->tab[i][1] == ' ')
			return (printf("Error\nthere is a bad elem\n"), 0);
		if (data->tab[i][0] == 'W' && data->tab[i][1] == ' ')
			return (printf("Error\nthere is a bad elem\n"), 0);
		if (data->tab[i][0] == 'E' && data->tab[i][1] == ' ')
			return (printf("Error\nthere is a bad elem\n"), 0);
		i++;
	}
	return (1);
}

int	verif_char_map_line(char *line)
{
	int	j;

	j = 0;
	while (line[j] != '\0' && line[j] != '\n')
	{
		if (line[j] != 'S' && line[j] != 'E' && line[j] != 'W' && line[j] != 'N'
			&& line[j] != '1' && line[j] != '0' && line[j] != ' ')
			return (0);
		j++;
	}
	return (1);
}

void	check_player(t_env *data, char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if ((line[j] == 'W') || (line[j] == 'S') || (line[j] == 'N')
			|| (line[j] == 'E'))
		{
			if (line[j] == 'W')
				data->map.player = 'W';
			if (line[j] == 'S')
				data->map.player = 'S';
			if (line[j] == 'E')
				data->map.player = 'E';
			if (line[j] == 'N')
				data->map.player = 'N';
			data->p += 1;
			data->map.pos_j = j;
		}
		j++;
	}
}

int	verif_map_is_closed(char *line)
{
	int	size;

	size = ft_strlen(line);
	if (line[0] == '0' || (size > 1 && line[size - 2] == '0'))
		return (0);
	return (1);
}

int	verif_map_lines(t_env *data, int j)
{
	int	i;

	i = 0;
	while (i < data->map.size)
	{
		if ((data->tab[j + i][0] == '\n' ) && ((j + i + 1) < data->map.size + j)
			&& data->tab[j + i + 1][0] != '\n')
			return (printf("Error\ngive me a map without new line between\n"), 0);
		if (verif_char_map_line(data->tab[j + i]) == 0)
			return (printf("Error\nbad character in map\n"), 0);
		check_player(data, data->tab[j + i]);
		if (data->p > 1)
			return (printf("Error\ntoo many players\n"), 0);
		if (verif_map_is_closed(data->tab[j + i]) == 0)
			return (printf("Error\nInvalid map\n"), 0);
		i++;
	}
	if (data->p != 1)
		return (printf("Error\nplayer is missing\n"), 0);
	return (1);
}
