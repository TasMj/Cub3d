/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:19:14 by aclement          #+#    #+#             */
/*   Updated: 2023/10/22 22:34:23 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_colors(t_mlx *mlx, t_elem *elem)
{
	mini_split_trim(elem->f, elem, 'f');
	mini_split_trim(elem->c, elem, 'c');
	printf("f[0]: %d\n", elem->floor[0]);
	printf("f[1]: %d\n", elem->floor[1]);
	printf("f[2]: %d\n", elem->floor[2]);
	printf("c[0]: %d\n", elem->ceil[0]);
	printf("c[1]: %d\n", elem->ceil[1]);
	printf("c[2]: %d\n", elem->ceil[2]);
	mlx->img.floor = encode_rgb(elem->floor[0], elem->floor[1], elem->floor[2]);
	mlx->img.ceil = encode_rgb(elem->ceil[0], elem->ceil[1], elem->ceil[2]);
}

void	init_textures(t_textures *texture)
{
	texture[0].addr = mlx_get_data_addr(texture[0].mlx_img, \
		&texture[0].bpp, &texture[0].line_len, &texture[0].endian);
	texture[1].addr = mlx_get_data_addr(texture[1].mlx_img, \
		&texture[1].bpp, &texture[1].line_len, &texture[1].endian);
	texture[2].addr = mlx_get_data_addr(texture[2].mlx_img, \
		&texture[2].bpp, &texture[2].line_len, &texture[2].endian);
	texture[3].addr = mlx_get_data_addr(texture[3].mlx_img, \
		&texture[3].bpp, &texture[3].line_len, &texture[3].endian);
}

void	init_adress_window(t_mlx *mlx)
{
	mlx->img.mlx_img = mlx_new_image(mlx->mlx_ptr, SCREENWIDTH, \
		SCREENHEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.mlx_img, \
		&mlx->img.bpp, &mlx->img.line_len, &mlx->img.endian);
}

int	init_imgs(t_mlx *mlx, t_textures *texture, t_elem *elem)
{
	texture[0].mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		elem->no, &texture[0].w, &texture[0].h);
	if (!texture[0].mlx_img || texture[0].w != IMG_WIDTH || \
		texture[0].h != IMG_HEIGHT)
		return (printf("Error\nNorth image gone wrong\n"), 0);
	texture[1].mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		elem->so, &texture[1].w, &texture[1].h);
	if (!texture[1].mlx_img || texture[1].w != IMG_WIDTH || \
		texture[1].h != IMG_HEIGHT)
		return (printf("Error\nSouth image gone wrong\n"), 0);
	texture[2].mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		elem->we, &texture[2].w, &texture[2].h);
	if (!texture[2].mlx_img || texture[2].w != IMG_WIDTH || \
		texture[2].h != IMG_HEIGHT)
		return (printf("Error\nWest image gone wrong\n"), 0);
	texture[3].mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		elem->ea, &texture[3].w, &texture[3].h);
	if (!texture[3].mlx_img || texture[3].w != IMG_WIDTH || \
		texture[3].h != IMG_HEIGHT)
		return (printf("Error\nEast image gone wrong\n"), 0);
	printf("%p\n", texture[0].mlx_img);
	printf("%p\n", texture[1].mlx_img);
	printf("%p\n", texture[2].mlx_img);
	printf("%p\n", texture[3].mlx_img);
	printf("2.w = %d && 2.h = %d\n", texture[2].w, texture[2].h);
	return (1);
}

int	create_window(t_mlx *mlx)
{
	//mlx->screen_width = SCREENWIDTH;
	//mlx->screen_height = SCREENHEIGHT;
	//mlx_get_screen_size(mlx->mlx_ptr, &mlx->sizex, &mlx->sizey);
	//if (mlx->screen_width > mlx->sizex)
	//	mlx->screen_width = mlx->sizex;
	//if (mlx->screen_height > mlx->sizey)
	//	mlx->screen_height = mlx->sizey;
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, SCREENWIDTH, \
		SCREENHEIGHT, "CUB3D");
	if (!mlx->mlx_win)
		return (0);
	return (1);
}

void	init_tab_float(t_map *map)
{
    int     i;
    int     j;
    double  i_float;
    double  j_float;
    double  scale;

    scale = 1.0;
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
            i_float = i * scale;
            j_float = j * scale;
			map->map_float[i][j].type = map->fmap[i][j];
            map->map_float[i][j].x = i_float;
            map->map_float[i][j].y = j_float;
			// printf("{(%d, %d) --> %c}", i, j, map->map_float[i][j].type);
			printf("%c", map->map_float[i][j].type);
            j++;
        }
		printf("\n");
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
	mlx->coord.pos_start = mlx->env.map.tab[find_y(&mlx->env.map)][find_x(&mlx->env.map)];
	init_pos_player(mlx);
	mlx->tab_len_ray = malloc(sizeof(double) * SCREENWIDTH);
    if (!mlx->tab_len_ray)
        return ;
    mlx->tab_angle_ray = malloc(sizeof(double) * SCREENWIDTH);
    if (!mlx->tab_angle_ray)
		return ;
    // printf("init: (%f, %f)\n  {%c}\n", mlx->coord.pos_player_y, mlx->coord.pos_player_x, mlx->env.map.tab[find_y(&mlx->env.map)][find_x(&mlx->env.map)]);
}