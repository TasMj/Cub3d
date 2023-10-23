/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:19:14 by tas               #+#    #+#             */
/*   Updated: 2023/10/23 08:52:05 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_recup_map(t_env *data, char **av)
{
	int		i;
	char	*stock;

	i = 0;
	stock = "";
	data->open_file = open(av[1], O_RDONLY);
	if (data->open_file == -1)
	{
		printf("Error\nCannot open map\n");
		ft_free_tab(data);
		exit(0);
	}
	while (stock != NULL)
	{
		stock = get_next_line(data->open_file);
		if (stock)
			free(stock);
		i++;
	}
	data->tab = malloc(sizeof(char *) * i);
	if (!(data->tab))
		return (-1);
	data->tab[i - 1] = NULL;
	close(data->open_file);
	return (i - 1);
}

void	ft_line_by_line(t_env *data, char **av)
{
	int	j;

	data->size = ft_recup_map(data, av);
	if (data->size == 0)
	{
		printf("Error\nplease give me a map...\n");
		ft_free_tab(data);
		exit(0);
	}
	j = 0;
	data->open_file = open(av[1], O_RDONLY);
	while (j < data->size)
		data->tab[j++] = get_next_line(data->open_file);
	close(data->open_file);
	if (ft_check_elements(data) == 0)
	{
		ft_free_tab(data);
		exit(0);
	}
	if (ft_check_map(data) == 0)
	{
		ft_free_tab(data);
		exit(0);
	}
}

int	ft_verif_extansion(char *av)
{
	char	*ext;
	int		i_av;
	int		i_ext;

	ext = ".cub";
	i_av = ft_strlen(av);
	i_ext = ft_strlen(ext);
	if (i_av >= i_ext && ft_strcmp(av + i_av - i_ext, ext) == 0)
		return (0);
	else
	{
		printf("Error\nthe map needs to end by '.cub'\n");
		return (1);
	}
}

int	launch_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (0);
	if (create_window(mlx) == 0)
		return (0);
	if (init_imgs(mlx, mlx->texture, &mlx->env.elem) == 0)
		return (0);
	init_colors(mlx, &mlx->env.elem);
	init_textures(mlx->texture);
	init_adress_window(mlx);
	init_param(mlx);
	mlx_hook(mlx->mlx_win, 17, 0, close_win, mlx->mlx_ptr);
	mlx_key_hook(mlx->mlx_win, keypress, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	ft_memset(&mlx, 0, sizeof(mlx));
	if (ac != 2)
		printf("Error\ntoo much or too few arguments\n");
	else
	{
		if (ft_verif_extansion(av[1]) == 0)
		{
			ft_line_by_line(&mlx.env, av);
			recup_map(&mlx.env.map);
			if (launch_mlx(&mlx) == 0)
				return (ft_close_window(&mlx), 0);
		}
		ft_close_window(&mlx);
	}
	return (0);
}
