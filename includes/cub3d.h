/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:25:08 by tas               #+#    #+#             */
/*   Updated: 2023/10/23 08:58:21 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/******************************************************************************/
/*                                includes                                    */
/******************************************************************************/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <strings.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../includes/get_next_line_bis.h"

/******************************************************************************/
/*                                  macros                                    */
/******************************************************************************/

# define IMG_WIDTH 64
# define IMG_HEIGHT 64
# define SCREENWIDTH 1000
# define SCREENHEIGHT 800
# define PI 3.141592

/******************************************************************************/
/*                                  struct                                    */
/******************************************************************************/

typedef struct s_point
{
	double	x;
	double	y;
	char	type;
}			t_point;

typedef struct s_elem
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		floor[3];
	int		ceil[3];
}			t_elem;

typedef struct s_map
{
	char	**tab;
	int		pos_i;
	int		pos_j;
	char	player;
	int		size;
	int		mapwidth;
	int		mapheight;
	double	ang_x;
	double	ang_y;
	double	angle;
	double	rad_angle;
	double	rapport_x;
	double	rapport_y;
	t_point	**map_float;
	char	**fmap;
}			t_map;

typedef struct s_env
{
	t_elem	elem;
	t_map	map;
	int		open_file;
	int		size;
	char	**tab;
	int		p;
}			t_env;

typedef struct s_coord
{
	double	end_x;
	double	end_y;
	int		map_i;
	int		map_j;
	double	map_x;
	double	map_y;
	double	grille_x;
	double	grille_y;
	double	grille_i;
	double	grille_j;
	double	pos_player_x;
	double	pos_player_y;
	double	current_angle;
	char	pos_start;
	double	rotated_x;
	double	rotated_y;
}			t_coord;

typedef struct s_textures
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
	int		floor;
	int		ceil;
	int		w;
	int		h;
}			t_textures;

typedef struct s_mlx
{
	t_env		env;
	t_textures	texture[4];
	t_textures	img;
	t_textures	prev_img;
	t_coord		coord;
	double		seg_angle;
	void		*mlx_ptr;
	void		*mlx_win;
	int			sizex;
	int			sizey;
	float		screen_width;
	float		screen_height;
	double		*tab_len_ray;
	double		*tab_angle_ray;
}				t_mlx;

/******************************************************************************/
/*                                  fonctions                                 */
/******************************************************************************/

/*
3d
*/
void	draw_3d(t_mlx *mlx);
void	draw_column(t_mlx *mlx, int x, int nb_ray);

/*
raycasting
*/
int		ray_intersect_wall(double ray_x, double ray_y, char **map, t_mlx *mlx);
double	calcul_lenght(t_mlx *mlx, double ray_x, double ray_y, double i);
void	raycasting(t_mlx *mlx, t_coord *coord);


/*
keypress.c
*/
int		keypress(int keycode, t_mlx *mlx);
int		key_wsda(int keycode, t_mlx *mlx, t_coord *coord);
int		key_ad(t_mlx *mlx, int keycode, t_coord *c);
int		key_sw(t_mlx *mlx, int keycode, t_coord *c);
int		key_arrow(int keycode, t_mlx *mlx, t_coord *coord);

/*
recup_map.c
*/
void	recup_map(t_map *map);

/*
pixel.c
*/
void	put_pixel_map(t_mlx *mlx, t_textures *img);
void	put_pixel(t_textures *img, int x, int y, int color);
void	draw_grille(t_textures *img, t_map *map, t_mlx *mlx);
void	draw_grille_annex(t_textures *img, t_coord *c, t_mlx *mlx);

/*
free.c
*/
void	ft_free_tab(t_env *data);
void	ft_free_mlx(t_mlx *mlx);
int		ft_close_window(t_mlx *mlx);
void	ft_free_img(t_mlx *mlx);
int		close_win(void *mlx);
void	free_tab_float(t_map *map);
void	ft_free_fmap(t_map *map);
void	free_mlx_tab(t_mlx *mlx);

/*
check_fc.c
*/
int		ft_check_c(t_env *data);
int		ft_check_f(t_env *data);
int		verif_size_colors(char *line, int nb_vir);
int		get_colors(t_env *data, char *line, char c);
int		verif_digit(char *line);

/*
verif_textures.c
*/
int		ft_verif_text_xpm(char *text);
int		get_texture(t_env *data, char *line, char c);
int		keep_path_text(t_env *data, char *line, char c);
int		encode_rgb(int red, int green, int blue);

/*
check_nswe.c
*/
int		ft_check_no(t_env *data);
int		ft_check_so(t_env *data);
int		ft_check_ea(t_env *data);
int		ft_check_we(t_env *data);

/*
verif_line_by_line.c
*/
int		verif_map_lines(t_env *data, int j);
int		verif_map_is_closed(char *line);
void	check_player(t_env *data, char *line);
int		verif_char_map_line(char *line);
int		ft_verif_bad_elem(t_env *data);

/*
ft_fornorme.c
*/
char	*tmp_size_colors(int i, char *line, int nb);
int		tmp_verif_digit(char *line);
int		tmp_check_fc(t_env *data, int i, char c);
int		tmp_check_nswe(t_env *data, int i, char c);
void	mini_split_trim(char *str, t_elem *elem, char fc);

/*
verif_map.c
*/
int		verif_zero_player(t_map *map, size_t i, size_t j);
int		verif_map(t_map *map);

/*
elements_parse.c
*/
int		check_no_double_elem(t_env *data, int i, char c);
int		ft_check_elements(t_env *data);
int		get_n(char *line);
int		ft_check_map(t_env *data);

/*
init.c
*/
int		init_imgs(t_mlx *mlx, t_textures *texture, t_elem *elem);
void	init_textures(t_textures *texture);
void	init_adress_window(t_mlx *mlx);
int		create_window(t_mlx *mlx);
void	init_colors(t_mlx *mlx, t_elem *elem);
void	init_param(t_mlx *mlx);
void	init_tab_float(t_map *map);
void	init_pos_player(t_mlx *mlx);

/*
main.c
*/
int		ft_verif_extansion(char *av);
int		ft_recup_map(t_env *data, char **av);
void	ft_line_by_line(t_env *data, char **av);
int		launch_mlx(t_mlx *mlx);
int		main(int ac, char **av);

/*
tools.c
*/
int		find_x(t_map *map);
int		find_y(t_map *map);

#endif