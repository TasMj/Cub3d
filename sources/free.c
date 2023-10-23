/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:47:55 by aclement          #+#    #+#             */
/*   Updated: 2023/10/23 00:40:56 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_tab(t_env *data)
{
	int	i;

	i = 0;
	if (!data->tab)
		return ;
	while (i < data->size)
	{
		if (data->tab[i])
			free(data->tab[i]);
		i++;
	}
	if (data->tab)
		free(data->tab);
	if (data->map.tab)
		free(data->map.tab);
}

void	ft_free_fmap(t_map *map)
{
	int	i;

	i = 0;
	if (!map->fmap)
		return ;
	while (i < map->mapheight)
	{
		if (map->fmap[i])
			free(map->fmap[i]);
		i++;
	}
	if (map->fmap)
		free(map->fmap);
}

void	free_tab_float(t_map *map)
{
	int	i;

	i = 0;
	if (!map->map_float)
		return ;
	while (i < map->mapheight)
	{
		if (map->map_float[i])
			free(map->map_float[i]);
		i++;
	}
	if (map->map_float)
		free(map->map_float);
}

void	ft_free_mlx(t_mlx *mlx)
{
	ft_free_tab(&mlx->env);
}

void	free_mlx_tab(t_mlx *mlx)
{
	if (mlx->tab_angle_ray)
		free(mlx->tab_angle_ray);
	if (mlx->tab_len_ray)
		free(mlx->tab_len_ray);
}
