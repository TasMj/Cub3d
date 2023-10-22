/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:00:13 by aclement          #+#    #+#             */
/*   Updated: 2023/09/28 17:46:10 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_c(t_env *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		if (data->tab[i][0] == '\n' || data->tab[i][0] == 'S'
			|| data->tab[i][0] == 'W' || data->tab[i][0] == 'E'
				|| data->tab[i][0] == 'F' || data->tab[i][0] == 'N')
			i++;
		else if (data->tab[i][0] == 'C' && data->tab[i][1] == ' ')
		{
			if (tmp_check_fc(data, i, 'C') == 1)
				return (1);
			else
				return (0);
		}
		else
		{
			printf("Error\nInvalid char between elements or Ceil is missing\n");
			return (0);
		}
	}
	return (0);
}

int	ft_check_f(t_env *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		if (data->tab[i][0] == '\n' || data->tab[i][0] == 'S'
			|| data->tab[i][0] == 'W' || data->tab[i][0] == 'E'
				|| data->tab[i][0] == 'C' || data->tab[i][0] == 'N')
			i++;
		else if (data->tab[i][0] == 'F' && data->tab[i][1] == ' ')
		{
			if (tmp_check_fc(data, i, 'F') == 1)
				return (1);
			else
				return (0);
		}
		else
		{
			printf("Error\nInvalid char between elements or Floor is missing\n");
			return (0);
		}
	}
	return (0);
}

// return (0) : error et imprime 0 255
// return 1 si ok

int	verif_size_colors(char *line, int nb_vir)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line[i] != '\0' && line[i] != ',' && line[i] != '\n')
		i++;
	if (nb_vir >= 1)
	{
		i++;
		tmp = tmp_size_colors(i, line, 1);
		if (tmp == NULL)
			return (0);
		i--;
	}
	else
	{
		tmp = tmp_size_colors(i, line, 2);
		if (tmp == NULL)
			return (0);
	}
	if (ft_atoi(tmp) >= 0 && ft_atoi(tmp) <= 255)
		return (free(tmp), i);
	return (free(tmp), 0);
}

int	verif_digit(char *line)
{
	int	vir;

	vir = tmp_verif_digit(line);
	if (vir == 2)
		return (1);
	if (vir == -1)
		return (0);
	return (printf("Error\nkeep the R,G,B format\n"), 0);
}

int	get_colors(t_env *data, char *line, char c)
{
	int	i;
	int	size;
	int	j;

	i = 0;
	size = ft_strlen(line);
	if (line[size - 1] == '\n')
		line[size -1] = '\0';
	while (line[i] && line[i] == ' ')
		i++;
	j = i;
	while (line[j])
	{
		if (ft_isdigit(line[j]) == 1 || line[j] == ',')
			j++;
		else
			return (printf("Error\nkeep the R,G,B format\n"), 0);
	}
	if (verif_digit(line + i))
		return (keep_path_text(data, line + i, c));
	return (0);
}
