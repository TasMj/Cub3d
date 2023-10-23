/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:50:29 by tmejri            #+#    #+#             */
/*   Updated: 2023/10/23 09:15:17 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_ad(t_mlx *mlx, int keycode, t_coord *c)
{
	if (keycode == 119 && ((c->pos_player_x + 0.1 * cos(c->current_angle)) \
	<= mlx->env.map.mapwidth)
		&& (mlx->env.map.fmap[(int)(c->pos_player_y - 0.1 * \
		sin(c->current_angle))][(int)(c->pos_player_x + 0.1 * \
		cos(c->current_angle))] != '1'))
	{
		c->pos_player_x = c->pos_player_x + 0.1 * cos(c->current_angle);
		c->pos_player_y = c->pos_player_y - 0.1 * sin(c->current_angle);
	}
	else if (keycode == 115 && ((c->pos_player_x - 0.1 * \
	cos(c->current_angle)) >= 0)
		&& mlx->env.map.fmap[(int)(c->pos_player_y + 0.1 * \
		sin(c->current_angle))][(int)(c->pos_player_x - 0.1 * \
		cos(c->current_angle))] != '1')
	{
		c->pos_player_x = c->pos_player_x - 0.1 * cos(c->current_angle);
		c->pos_player_y = c->pos_player_y + 0.1 * sin(c->current_angle);
	}
	return (0);
}

int	key_sw(t_mlx *mlx, int keycode, t_coord *c)
{
	if (keycode == 97 && ((c->pos_player_y - 0.1 * sin(c->current_angle - \
	(PI / 2))) <= mlx->env.map.mapheight)
		&& mlx->env.map.fmap[(int)(c->pos_player_y - 0.1 * sin(c->current_angle - \
	(PI / 2)))][(int)(c->pos_player_x + 0.1 * \
	cos(c->current_angle - (PI / 2)))] != '1')
	{
		c->pos_player_x = c->pos_player_x + \
		0.1 * cos(c->current_angle - (PI / 2));
		c->pos_player_y = c->pos_player_y - \
		0.1 * sin(c->current_angle - (PI / 2));
	}
	else if (keycode == 100 && ((c->pos_player_y + 0.1 * \
	sin(c->current_angle - (PI / 2))) >= 0)
		&& mlx->env.map.fmap[(int)(c->pos_player_y + 0.1 * sin(c->current_angle - \
	(PI / 2)))][(int)(c->pos_player_x - 0.1 * \
	cos(c->current_angle - (PI / 2)))] != '1')
	{
		c->pos_player_x = c->pos_player_x - 0.1 * \
		cos(c->current_angle - (PI / 2));
		c->pos_player_y = c->pos_player_y + 0.1 * \
		sin(c->current_angle - (PI / 2));
	}
	return (0);
}

int	key_wsda(int keycode, t_mlx *mlx, t_coord *coord)
{
	if (!((coord->pos_player_x >= 0 && coord->pos_player_x \
	<= (mlx->env.map.mapwidth))
			&& (coord->pos_player_y >= 0 && coord->pos_player_y \
			<= (mlx->env.map.mapheight))))
				return (1);
	if (key_ad(mlx, keycode, coord) == 1)
		return (0);
	if (key_sw(mlx, keycode, coord) == 1)
		return (0);
	return (0);
}

int	key_arrow(int keycode, t_mlx *mlx, t_coord *coord)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.mlx_img);
	mlx->img.mlx_img = mlx_new_image(mlx->mlx_ptr, SCREENWIDTH, \
	SCREENHEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.mlx_img, \
	&mlx->img.bpp, &mlx->img.line_len, &mlx->img.endian);
	if (keycode == 65363)
		mlx->seg_angle += 0.1;
	else if (keycode == 65361)
		mlx->seg_angle -= 0.1;
	coord->current_angle = mlx->seg_angle;
	return (0);
}

int	keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 97 || keycode == 100 || keycode == 115 || keycode == 119)
		key_wsda(keycode, mlx, &mlx->coord);
	else if (keycode >= 65361 && keycode <= 65364)
		key_arrow(keycode, mlx, &mlx->coord);
	else if (keycode == 65307)
	{
		close_win(mlx->mlx_ptr);
		return (1);
	}
	raycasting(mlx, &mlx->coord);
	draw_3d(mlx);
	return (0);
}
