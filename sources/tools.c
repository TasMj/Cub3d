/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:43:26 by aclement          #+#    #+#             */
/*   Updated: 2023/10/21 21:08:07 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int find_x(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->mapheight)
	{
		j = 0;
		while (j < map->mapwidth && map->tab[i][j] != '\0')
		{
			if (map->tab[i][j] && (map->tab[i][j] == 'N' || map->tab[i][j] == 'S' || map->tab[i][j] == 'E' || map->tab[i][j] == 'W'))
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int find_y(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->mapheight)
	{
		j = 0;
		while (j < map->mapwidth && map->tab[i][j] != '\0')
		{
			if (map->tab[i][j] == 'N' || map->tab[i][j] == 'S' || map->tab[i][j] == 'E' || map->tab[i][j] == 'W')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}
