/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 01:00:42 by tas               #+#    #+#             */
/*   Updated: 2023/10/23 09:04:08 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ray_intersect_wall(double ray_x, double ray_y, char **map, t_mlx *mlx)
{
	int	map_x;
	int	map_y;

	map_x = (int)(ray_x);
	map_y = (int)(ray_y);
	if (!(map_x >= 0 && map_x < mlx->env.map.mapwidth && map_y >= 0 \
		&& map_y < mlx->env.map.mapheight))
		return (1);
	if (map[map_y][map_x] == '1')
		return (1);
	return (0);
}

double	calcul_lenght(t_mlx *mlx, double ray_x, double ray_y, double i)
{
	double	ray_angle;
	double	step;
	double	ray_lenght;
	double	ray_angle_diff;

	ray_angle = i;
	step = 0.01;
	ray_lenght = 0.0;
	while (ray_x >= 0 && ray_x < mlx->env.map.mapwidth \
		&& ray_y >= 0 && ray_y < mlx->env.map.mapheight)
	{
		if (ray_intersect_wall(ray_x, ray_y, mlx->env.map.fmap, mlx))
			break ;
		ray_x += step * cos(ray_angle);
		ray_y -= step * sin(ray_angle);
		ray_lenght += step;
	}
	ray_angle_diff = mlx->seg_angle - ray_angle;
	ray_lenght = ray_lenght * cos(ray_angle_diff);
	return (ray_lenght);
}

void	raycasting(t_mlx *mlx, t_coord *coord)
{
	double	i;
	int		ray_nb;
	double	ray_length;
	double	ray_x;
	double	ray_y;

	ray_nb = 0;
	i = mlx->seg_angle - (PI / 6);
	ray_x = coord->pos_player_x;
	ray_y = coord->pos_player_y;
	while (ray_nb < (SCREENWIDTH / 2))
	{
		ray_length = calcul_lenght(mlx, ray_x, ray_y, i);
		mlx->tab_len_ray[ray_nb] = ray_length;
		mlx->tab_angle_ray[ray_nb] = i;
		i += (PI / 6) / (SCREENWIDTH / 2);
		ray_nb++;
	}
	i = mlx->seg_angle;
	while (ray_nb < SCREENWIDTH)
	{
		ray_length = calcul_lenght(mlx, ray_x, ray_y, i);
		mlx->tab_len_ray[ray_nb] = ray_length;
		mlx->tab_angle_ray[ray_nb] = i;
		i += (PI / 6) / (SCREENWIDTH / 2);
		ray_nb++;
	}
}
