/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 00:50:32 by tas               #+#    #+#             */
/*   Updated: 2023/10/23 00:55:57 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_tab_float(t_map *map)
{
	int		i;
	int		j;
	double	i_float;
	double	j_float;

	map->map_float = malloc(sizeof(t_point *) * map->mapheight);
	if (!map->map_float)
		return ;
	i = 0;
	while (i < map->mapheight)
	{
		map->map_float[i] = malloc(sizeof(t_point) * map->mapwidth);
		if (! map->map_float[i])
			return ;
		j = 0;
		while (j < map->mapwidth)
		{
			i_float = i * 1.0;
			j_float = j * 1.0;
			map->map_float[i][j].type = map->fmap[i][j];
			map->map_float[i][j].x = i_float;
			map->map_float[i][j].y = j_float;
			j++;
		}
		i++;
	}
}

void	init_pos_player(t_mlx *mlx)
{
	if (mlx->coord.pos_start == 'N')
		mlx->seg_angle = PI / 2;
	if (mlx->coord.pos_start == 'S')
		mlx->seg_angle = -PI / 2;
	if (mlx->coord.pos_start == 'E')
		mlx->seg_angle = PI * 2;
	if (mlx->coord.pos_start == 'W')
		mlx->seg_angle = PI;
}

void	init_param(t_mlx *mlx)
{
	mlx->env.map.angle = atan2(mlx->env.map.ang_x, mlx->env.map.ang_y);
	mlx->env.map.rad_angle = mlx->env.map.angle * (180.0 / PI);
	mlx->prev_img = mlx->img;
	init_tab_float(&mlx->env.map);
	mlx->coord.pos_player_x = (double)(find_x(&mlx->env.map) + 0.5);
	mlx->coord.pos_player_y = (double)(find_y(&mlx->env.map) + 0.5);
	mlx->coord.pos_start = \
	mlx->env.map.tab[find_y(&mlx->env.map)][find_x(&mlx->env.map)];
	init_pos_player(mlx);
	mlx->tab_len_ray = malloc(sizeof(double) * SCREENWIDTH);
	if (!mlx->tab_len_ray)
		return ;
	mlx->tab_angle_ray = malloc(sizeof(double) * SCREENWIDTH);
	if (!mlx->tab_angle_ray)
		return ;
}
