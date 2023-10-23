/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:58:52 by aclement          #+#    #+#             */
/*   Updated: 2023/10/23 09:07:51 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
