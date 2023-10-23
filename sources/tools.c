/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:43:26 by aclement          #+#    #+#             */
/*   Updated: 2023/10/23 09:16:35 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_x(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->mapheight)
	{
		j = 0;
		while (j < map->mapwidth && map->tab[i][j] != '\0')
		{
			if (map->tab[i][j] && (map->tab[i][j] == 'N' \
				|| map->tab[i][j] == 'S' || map->tab[i][j] == 'E' \
					|| map->tab[i][j] == 'W'))
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int	find_y(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->mapheight)
	{
		j = 0;
		while (j < map->mapwidth && map->tab[i][j] != '\0')
		{
			if (map->tab[i][j] == 'N' || map->tab[i][j] == 'S' \
				|| map->tab[i][j] == 'E' || map->tab[i][j] == 'W')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

void	recup_map(t_map *map)
{
	int	i;
	int	j;

	map->fmap = malloc(sizeof(char *) * map->mapheight);
	if (!map->fmap)
		return ;
	j = 0;
	while (j < map->mapheight)
	{
		i = 0;
		map->fmap[j] = malloc(sizeof(char) * (map->mapwidth));
		if (! map->fmap[j])
			return ;
		while (map->tab[j][i] != '\0')
		{
			map->fmap[j][i] = map->tab[j][i];
			i++;
		}
		while (i < map->mapwidth)
			map->fmap[j][i++] = '1';
		j++;
	}
}
