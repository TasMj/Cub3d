/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:07:05 by aclement          #+#    #+#             */
/*   Updated: 2023/10/23 09:12:17 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_verif_text_xpm(char *text)
{
	char	*ext;
	int		i_text;
	int		i_ext;

	ext = ".xpm";
	i_text = ft_strlen(text);
	i_ext = ft_strlen(ext);
	if (i_text >= i_ext && ft_strcmp(text + i_text - i_ext, ext) == 0)
		return (0);
	else
	{
		printf("Error\nthe texture needs to end by '.xpm'\n");
		return (1);
	}
}

int	keep_path_text(t_env *data, char *line, char c)
{
	if (c == 'N')
		return (data->elem.no = line, 1);
	else if (c == 'S')
		return (data->elem.so = line, 1);
	else if (c == 'W')
		return (data->elem.we = line, 1);
	else if (c == 'E')
		return (data->elem.ea = line, 1);
	else if (c == 'F')
		return (data->elem.f = line, 1);
	else if (c == 'C')
		return (data->elem.c = line, 1);
	else
		return (0);
}

int	get_texture(t_env *data, char *line, char c)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(line);
	if (line[size - 1] == '\n')
		line[size - 1] = '\0';
	if (ft_verif_text_xpm(line) == 0)
	{
		while (line[i] && line[i] == ' ')
			i++;
		return (keep_path_text(data, line + i, c));
	}
	else
		return (0);
}

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}
