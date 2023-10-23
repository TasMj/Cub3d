/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_delet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 00:59:03 by tas               #+#    #+#             */
/*   Updated: 2023/10/23 09:06:22 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_perso(t_mlx *mlx, t_coord *coord)
{
    int size = 6;
    double angle = mlx->seg_angle;
    double cosAngle = cos(angle);
    double sinAngle = sin(angle);

	int i = -size;
	while (i <= size)
    {
		int j = -size;
		while (j <= size)
        {
            coord->rotated_x = i * cosAngle + j * sinAngle;
            coord->rotated_y = -i * sinAngle + j * cosAngle;
            double pixelY = coord->pos_player_x * mlx->env.map.rapport_y + coord->rotated_x;
            double pixelX = coord->pos_player_y * mlx->env.map.rapport_x + coord->rotated_y;
            if (pixelX >= 0 && pixelX < SCREENHEIGHT && pixelY >= 0 && pixelY < SCREENWIDTH)
                mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, pixelY, pixelX, 0x9400D3);
            j++;
        }
		i++;
    }
}

void draw_seg(t_mlx *mlx, t_coord *coord, double ray_lengh, double angle, int color)
{
    double x;
    double y;
    double step;
    
    step = 0.01;
    x = coord->pos_player_x * cos(angle);
    y = coord->pos_player_y* sin(angle);
    while (step <= ray_lengh) 
	{
        x = coord->pos_player_x + step * cos(angle);
        y = coord->pos_player_y - step * sin(angle);
        if (x < 0 || y < 0 || x >= mlx->env.map.mapwidth || y >= mlx->env.map.mapheight) {
            break;
        }
        mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, (x * mlx->env.map.rapport_y), (y * mlx->env.map.rapport_x), color);
        step += 0.1;
    }
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
	while (mlx->coord.map_i < mlx->env.map.mapheight)
	{
		mlx->coord.map_j = 0;
		while (mlx->coord.map_j < mlx->env.map.mapwidth)
		{
			if (mlx->env.map.fmap[mlx->coord.map_i][mlx->coord.map_j] == '0' || mlx->env.map.fmap[mlx->coord.map_i][mlx->coord.map_j] == ' ')
			color = 0x00CC66FF;
			else if (mlx->env.map.fmap[mlx->coord.map_i][mlx->coord.map_j] == '1')
				color = 0x00FFFF99;
			else if (mlx->env.map.fmap[mlx->coord.map_i][mlx->coord.map_j] == mlx->coord.pos_start)
				color = 0x00CC66FF;
			start_x = (mlx->coord.map_i * mlx->env.map.rapport_x);
			start_y = (mlx->coord.map_j * mlx->env.map.rapport_y);
			mlx->coord.map_y = start_y;
			while (mlx->coord.map_y < start_y + mlx->env.map.rapport_y)
			{
				mlx->coord.map_x = start_x;
				while (mlx->coord.map_x < start_x + mlx->env.map.rapport_x)
				{
					mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, mlx->coord.map_y, mlx->coord.map_x, color);
					mlx->coord.map_x++;
				}
				mlx->coord.map_y++;
			}
			mlx->coord.map_j++;
		}
		mlx->coord.map_i++;
	}
	draw_grille(img, &mlx->env.map, mlx);
}

void	print_tab(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->mapheight)
	{
		i = 0;
		while (i < map->mapwidth)
		{
			printf("%c", map->fmap[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}
