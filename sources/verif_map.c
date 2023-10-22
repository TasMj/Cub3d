/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:27:03 by aclement          #+#    #+#             */
/*   Updated: 2023/10/20 15:57:52 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	verif_zero_player(t_map *map, size_t i, size_t j)
{
	//printf("i: %ld && j: %ld --> %c\n", i, j, map->tab[i][j]);
	//printf("len de i - 1: %ld && len de i + 1: %ld\n", ft_strlen(map->tab[i - 1]), ft_strlen(map->tab[i + 1]));
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
		printf("[%s]\n", map->tab[i]);
		while (map->tab[i][++j])
		{
		// printf("[%c]", map->tab[i][j]);
			if (map->tab[i][j] == '0')
				if (verif_zero_player(map, i, j) == 0)
					return (0);
			if ((map->tab[i][j] == 'N') || (map->tab[i][j] == 'S')
				|| (map->tab[i][j] == 'W') || (map->tab[i][j] == 'E'))
			{
				if (verif_zero_player(map, i, j) == 0)
					return (printf("Your player gonna escape...\n"), 0);
				map->pos_i = i;
			// printf("\n");
			}
		}
		if (j > max)
			max = j;
		i++;
	}
	map->mapheight = i;
	map->mapwidth = max;
	printf("pos du joueur %c: i = %d && j = %d\n", map->player, map->pos_i, map->pos_j);
	printf("h: %d  w: %d\n", map->mapheight, map->mapwidth);
	return (1);
}
