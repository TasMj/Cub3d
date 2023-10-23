/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:19:14 by aclement          #+#    #+#             */
/*   Updated: 2023/10/23 09:19:12 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_colors(t_mlx *mlx, t_elem *elem)
{
	mini_split_trim(elem->f, elem, 'f');
	mini_split_trim(elem->c, elem, 'c');
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
	return (1);
}

int	create_window(t_mlx *mlx)
{
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, SCREENWIDTH, \
		SCREENHEIGHT, "CUB3D");
	if (!mlx->mlx_win)
		return (0);
	return (1);
}
