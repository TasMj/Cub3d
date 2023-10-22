/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:47:55 by aclement          #+#    #+#             */
/*   Updated: 2023/10/22 18:55:05 by tmejri           ###   ########.fr       */
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

int	ft_close_window(t_mlx *mlx)
{
	ft_free_tab(&mlx->env);
	ft_free_fmap(&mlx->env.map);
	free_tab_float(&mlx->env.map);
	free_mlx_tab(mlx);
	if (mlx->mlx_ptr)
	{
		ft_free_img(mlx);
		if (mlx->mlx_win)
			mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	exit(10);
	return (0);
}

void	ft_free_img(t_mlx *mlx)
{
	if (mlx->texture[0].mlx_img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->texture[0].mlx_img);
	if (mlx->texture[1].mlx_img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->texture[1].mlx_img);
	if (mlx->texture[2].mlx_img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->texture[2].mlx_img);
	if (mlx->texture[3].mlx_img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->texture[3].mlx_img);
	if (mlx->img.mlx_img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.mlx_img);
}

int	close_win(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}
