/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:27:03 by aclement          #+#    #+#             */
/*   Updated: 2023/10/23 09:10:59 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	verif_zero_player(t_map *map, size_t i, size_t j)
{
	if (i == 0 || (int)i == map->size - 1)
		return (printf("Error\nInvalid map\n"), 0);
	if (j == 0 || j == ft_strlen(map->tab[i]) - 1)
		return (printf("Error\nInvalid map\n"), 0);
	if ((map->tab[i][j - 1] == ' ') || (map->tab[i][j + 1] == ' '))
		return (printf("Error\nInvalid map\n"), 0);
	if ((j >= ft_strlen(map->tab[i - 1])) || (j >= ft_strlen(map->tab[i + 1])))
		return (printf("Error\nInvalid map\n"), 0);
	if (map->tab[i - 1][j] == ' ' || map->tab[i + 1][j] == ' ')
		return (printf("Error\nInvalid map\n"), 0);
	return (1);
}

int	verif_map(t_map *map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (map->tab[i])
	{
		j = -1;
		while (map->tab[i][++j])
		{
			if (map->tab[i][j] == '0')
				if (verif_zero_player(map, i, j) == 0)
					return (0);
			if ((map->tab[i][j] == 'N') || (map->tab[i][j] == 'S')
				|| (map->tab[i][j] == 'W') || (map->tab[i][j] == 'E'))
			{
				if (verif_zero_player(map, i, j) == 0)
					return (printf("Your player gonna escape...\n"), 0);
				map->pos_i = i;
			}
		}
		if (j > max)
			max = j;
		i++;
	}
	map->mapheight = i;
	map->mapwidth = max;
	return (1);
}
