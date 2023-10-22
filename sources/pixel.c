/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:56:45 by aclement          #+#    #+#             */
/*   Updated: 2023/10/21 16:13:56 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_textures *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREENWIDTH || y < 0 || y >= SCREENHEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_grille_annex(t_textures *img, t_coord *c, t_mlx *mlx)
{
	(void)img;
	c->grille_j = 0;
	while (c->grille_j < SCREENHEIGHT)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, c->grille_i, c->grille_j, 0x00000000);
		c->grille_j++;
	}
	c->grille_i += c->grille_x;
}

void	draw_grille(t_textures *img, t_map *map, t_mlx *mlx)
{
	t_coord	c;

	c.grille_x = SCREENWIDTH / (double)map->mapwidth;
	c.grille_y = SCREENHEIGHT / (double)map->mapheight;
	c.grille_i = 0;
	c.grille_j = 0;
	while (c.grille_i <= SCREENWIDTH)
		draw_grille_annex(img, &c, mlx);
	c.grille_j = 0;
	while (c.grille_j <= SCREENHEIGHT)
	{
		c.grille_i = 0;
		while (c.grille_i < SCREENWIDTH)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, c.grille_i, c.grille_j, 0x00000000);
			c.grille_i++;
		}
		c.grille_j += c.grille_y;
	}
}

void	put_pixel_map(t_mlx *mlx, t_textures *img)
{
	(void)img;
	int	color;
	double	start_x;
	double	start_y;
	
	mlx->env.map.rapport_x = SCREENHEIGHT / (double)mlx->env.map.mapheight;
	mlx->env.map.rapport_y = SCREENWIDTH / (double)mlx->env.map.mapwidth;
	mlx->coord.map_i = 0;
	// printf("screenW: %f  screenH: %f\n", mlx->env.map.rapport_x, mlx->env.map.rapport_y);
	// printf("WWW: %f HHH: %f\n", mlx->env.map.mapwidth, mlx->env.map.mapheight);
	while (mlx->coord.map_i < mlx->env.map.mapheight)
	{
		// printf("j: %d\n", mlx->coord.map_j);
		mlx->coord.map_j = 0;
		while (mlx->coord.map_j < mlx->env.map.mapwidth)
		{
		// printf("i: %d\n", mlx->coord.map_i);
			if (mlx->env.map.fmap[mlx->coord.map_i][mlx->coord.map_j] == '0' || mlx->env.map.fmap[mlx->coord.map_i][mlx->coord.map_j] == ' ')
			color = 0x00CC66FF;
			else if (mlx->env.map.fmap[mlx->coord.map_i][mlx->coord.map_j] == '1')
				color = 0x00FFFF99;
			else if (mlx->env.map.fmap[mlx->coord.map_i][mlx->coord.map_j] == mlx->coord.pos_start)
				color = 0x00CC66FF;
			start_x = (mlx->coord.map_i * mlx->env.map.rapport_x);
			start_y = (mlx->coord.map_j * mlx->env.map.rapport_y);
			mlx->coord.map_y = start_y;
			// printf("start_x + rapp: %d  start_y + rapp: %d\n", start_x + mlx->env.map.rapport_x, start_y + mlx->env.map.rapport_y);
			// printf("start_x: %d  start_y: %d\n", start_x, start_y);
			while (mlx->coord.map_y < start_y + mlx->env.map.rapport_y)
			{
				mlx->coord.map_x = start_x;
				while (mlx->coord.map_x < start_x + mlx->env.map.rapport_x)
				{
					mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, mlx->coord.map_y, mlx->coord.map_x, color);
					// put_pixel(img, mlx->coord.map_x, mlx->coord.map_y, color);
					mlx->coord.map_x++;
				}
				mlx->coord.map_y++;
			}
			mlx->coord.map_j++;
			// put_pix_annex(&mlx->env.map, img, &mlx->coord, mlx);
		}
		mlx->coord.map_i++;
	}
	draw_grille(img, &mlx->env.map, mlx);
}