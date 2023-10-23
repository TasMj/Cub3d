/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 01:04:00 by tas               #+#    #+#             */
/*   Updated: 2023/10/23 09:13:32 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// get_color_texture(t_mlx *mlx, int y)
// {
//     int color;
//     int x = 0;
    
//     while(mlx->texture[0].)
//     {
        
//     }
//     return (color);
// }

void	draw_column(t_mlx *mlx, int x, int nb_ray)
{
	int y = 0;
	int wall = (int)(SCREENHEIGHT / (mlx->tab_len_ray[nb_ray]));
	int drawStart = (-wall / 2) + (SCREENHEIGHT / 2);
	if(drawStart < 0)
		drawStart = 0;
    int drawEnd = (wall / 2) + (SCREENHEIGHT / 2);
    if(drawEnd >= SCREENHEIGHT)
	 	drawEnd = SCREENHEIGHT - 1;
	while (y <= SCREENHEIGHT/2)
	{
        mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, y, encode_rgb(mlx->env.elem.ceil[0], mlx->env.elem.ceil[1], mlx->env.elem.ceil[2]));
		y++;
	}
	while (y < SCREENHEIGHT)
	{
        mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, y, encode_rgb(mlx->env.elem.floor[0], mlx->env.elem.floor[1], mlx->env.elem.floor[2]));
		y++;
	}
	while (drawStart <= drawEnd)
	{
        // int color = get_color_texture(mlx);
        // mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, drawStart, color);
        mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, drawStart, 0x00FFFF99);
		drawStart++;
	}
}

void	draw_3d(t_mlx *mlx)
{
	int	x;
	int	nb_ray;
	
    x = 0;
	nb_ray = 0;
	raycasting(mlx,&mlx->coord);
	while (x < SCREENWIDTH)
	{
		draw_column(mlx, x, nb_ray);
		x++;
		nb_ray++;
	}
}
