/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:50:29 by tmejri            #+#    #+#             */
/*   Updated: 2023/10/22 22:34:00 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_ad(t_mlx *mlx, int keycode, t_coord *c)
{
	if (keycode == 119 && ((c->pos_player_x + 0.1 * cos(c->current_angle)) <= mlx->env.map.mapwidth)
		&& (mlx->env.map.fmap[(int)(c->pos_player_y - 0.1 * sin(c->current_angle))][(int)(c->pos_player_x + 0.1 * cos(c->current_angle))] != '1')) //->
        {
		    c->pos_player_x = c->pos_player_x + 0.1 * cos(c->current_angle);
            c->pos_player_y = c->pos_player_y - 0.1 * sin(c->current_angle);
        }
	else if (keycode == 115 && ((c->pos_player_x - 0.1 * cos(c->current_angle)) >= 0)
		&& mlx->env.map.fmap[(int)(c->pos_player_y + 0.1 * sin(c->current_angle))][(int)(c->pos_player_x - 0.1 * cos(c->current_angle))] != '1') // <-
        {
    		c->pos_player_x = c->pos_player_x - 0.1 * cos(c->current_angle);
            c->pos_player_y = c->pos_player_y + 0.1 * sin(c->current_angle);
        }
	return (0);
}

int	key_sw(t_mlx *mlx, int keycode, t_coord *c)
{
	if (keycode == 97 && ((c->pos_player_y - 0.1 * sin(c->current_angle - (PI/2))) <= mlx->env.map.mapheight)
	&& mlx->env.map.fmap[(int)(c->pos_player_y - 0.1 * sin(c->current_angle - (PI/2)))][(int)(c->pos_player_x + 0.1 * cos(c->current_angle - (PI/2)))] != '1') // down
    {
        c->pos_player_x = c->pos_player_x + 0.1 * cos(c->current_angle - (PI/2));
        c->pos_player_y = c->pos_player_y - 0.1 * sin(c->current_angle - (PI/2));
    }
	else if (keycode == 100 && ((c->pos_player_y + 0.1 * sin(c->current_angle - (PI/2))) >= 0)
	&& mlx->env.map.fmap[(int)(c->pos_player_y + 0.1 * sin(c->current_angle - (PI/2)))][(int)(c->pos_player_x - 0.1 * cos(c->current_angle - (PI/2)))] != '1') // up
    {
        c->pos_player_x = c->pos_player_x - 0.1 * cos(c->current_angle - (PI/2));
        c->pos_player_y = c->pos_player_y + 0.1 * sin(c->current_angle - (PI/2));
    }
	return (0);
}

int	key_wsda(int keycode, t_mlx *mlx, t_coord *coord)
{
	if (!((coord->pos_player_x >= 0 && coord->pos_player_x <= (mlx->env.map.mapwidth))
			&& (coord->pos_player_y >= 0 && coord->pos_player_y <= (mlx->env.map.mapheight))))
			return (1);
	if (key_ad(mlx, keycode, coord) == 1)
		return (0);
	if (key_sw(mlx, keycode, coord) == 1)
		return (0);
	return (0);
}

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
            coord->rotatedX = i * cosAngle + j * sinAngle;
            coord->rotatedY = -i * sinAngle + j * cosAngle;
            double pixelY = coord->pos_player_x * mlx->env.map.rapport_y + coord->rotatedX;
            double pixelX = coord->pos_player_y * mlx->env.map.rapport_x + coord->rotatedY;
            if (pixelX >= 0 && pixelX < SCREENHEIGHT && pixelY >= 0 && pixelY < SCREENWIDTH)
                mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, pixelY, pixelX, 0x9400D3);
            j++;
        }
		i++;
    }
}

int	key_arrow(int keycode, t_mlx *mlx, t_coord *coord)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.mlx_img);
	mlx->img.mlx_img = mlx_new_image(mlx->mlx_ptr, SCREENWIDTH, SCREENHEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.mlx_img, &mlx->img.bpp 
	, &mlx->img.line_len, &mlx->img.endian);
	if (keycode == 65363)
		mlx->seg_angle += 0.1;
	else if (keycode == 65361)
		mlx->seg_angle -= 0.1;
	coord->current_angle = mlx->seg_angle;
	return (0);
}

void draw_seg(t_mlx *mlx, t_coord *coord, double ray_lengh, double angle, int color)
{
    double step = 0.01;
    double x = coord->pos_player_x * cos(angle);
    double y = coord->pos_player_y* sin(angle);
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

int ray_intersect_wall(double ray_x, double ray_y, char **map, t_mlx *mlx)
{
    int map_x;
    int map_y;
	
	map_x = (int)(ray_x);
	map_y = (int)(ray_y);
	if (!(map_x >= 0 && map_x < mlx->env.map.mapwidth && map_y >= 0 && map_y < mlx->env.map.mapheight))
		return (1);
    if (map[map_y][map_x] == '1')
        return (1);
    return 0;
}

double	calcul_lenght(t_mlx *mlx, t_coord *coord, double ray_x, double ray_y, double i)
{
	(void)coord;
    double ray_angle = i;
    double step = 0.01;
    double ray_lenght = 0.0;
    while (ray_x >= 0 && ray_x < mlx->env.map.mapwidth && ray_y >= 0 && ray_y < mlx->env.map.mapheight)
    {
        if (ray_intersect_wall(ray_x, ray_y, mlx->env.map.fmap, mlx))
            break;
        ray_x += step * cos(ray_angle);
        ray_y -= step * sin(ray_angle);
        ray_lenght += step;		
    }
    double ray_angle_diff = mlx->seg_angle - ray_angle;
    ray_lenght = ray_lenght * cos(ray_angle_diff);
    return ray_lenght;
}

void draw_ray(t_mlx *mlx, t_coord *coord)
{
    double i;
    int ray_nb;
    double ray_length;

    i =  (mlx->seg_angle - (PI/6));
    ray_nb = 0;
    double ray_x = coord->pos_player_x;
    double ray_y = coord->pos_player_y;
    while (ray_nb < (SCREENWIDTH / 2))
    {
        ray_length = calcul_lenght(mlx, coord, ray_x, ray_y, i);
        mlx->tab_len_ray[ray_nb] = ray_length;
        mlx->tab_angle_ray[ray_nb] = i;
        i += (PI/6)/(SCREENWIDTH/2);
        ray_nb++;
    }
    i =  mlx->seg_angle;
    while (ray_nb < SCREENWIDTH)
    {
        ray_length = calcul_lenght(mlx, coord, ray_x, ray_y, i);
        mlx->tab_len_ray[ray_nb] = ray_length;
        mlx->tab_angle_ray[ray_nb] = i;
        i += (PI/6)/(SCREENWIDTH/2);
        ray_nb++;
    }
}

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
        // mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, drawStart, 0x00FFFF99);
		drawStart++;
	}
}

void	draw_3d(t_mlx *mlx)
{
	int	x;
	int	nb_ray;
	
    x = 0;
	nb_ray = 0;
	draw_ray(mlx,&mlx->coord);
	while (x < SCREENWIDTH)
	{
		draw_column(mlx, x, nb_ray);
		x++;
		nb_ray++;
	}
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
	// put_pixel_map(mlx, &mlx->img);
	// draw_perso(mlx, &mlx->coord);
	// draw_seg(mlx, &mlx->coord, 50, mlx->seg_angle, 0x00993399);
	draw_ray(mlx, &mlx->coord);
	draw_3d(mlx);
	return (0);
}