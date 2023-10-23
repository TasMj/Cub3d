/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 00:39:51 by tas               #+#    #+#             */
/*   Updated: 2023/10/23 00:40:42 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
