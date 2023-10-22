/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:27:20 by aclement          #+#    #+#             */
/*   Updated: 2023/10/20 14:32:25 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_no_double_elem(t_env *data, int i, char c)
{
	i++;
	while (i < data->size)
	{
		if (data->tab[i][0] == c)
		{
			if (c == 'W' && data->tab[i][1] == 'E')
				return (printf("Error\ngive me one of each element\n"), 0);
			else if (c == 'E' && data->tab[i][1] == 'A')
				return (printf("Error\ngive me one of each element\n"), 0);
			else if (c == 'S' && data->tab[i][1] == 'O')
				return (printf("Error\ngive me one of each element\n"), 0);
			else if (c == 'N' && data->tab[i][1] == 'O')
				return (printf("Error\ngive me one of each element\n"), 0);
			else if (c == 'C' && data->tab[i][1] == ' ')
				return (printf("Error\ngive me one of each element\n"), 0);
			else if (c == 'F' && data->tab[i][1] == ' ')
				return (printf("Error\ngive me one of each element\n"), 0);
		}
		i++;
	}
	return (1);
}

//return 0 si erreur
//1 si ca coule

int	ft_check_elements(t_env *data)
{
	if (ft_check_no(data) == 0)
		return (0);
	printf("elem no : '%s'\n", data->elem.no);
	if (ft_check_so(data) == 0)
		return (0);
	printf("elem so : '%s'\n", data->elem.so);
	if (ft_check_we(data) == 0)
		return (0);
	printf("elem we : '%s'\n", data->elem.we);
	if (ft_check_ea(data) == 0)
		return (0);
	printf("elem ea : '%s'\n", data->elem.ea);
	if (ft_check_f(data) == 0)
		return (0);
	printf("elem f : '%s'\n", data->elem.f);
	if (ft_check_c(data) == 0)
		return (0);
	printf("elem c : '%s'\n", data->elem.c);
	return (1);
}

int	get_n(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	tmp_check_map(t_env *data, int j, int jj)
{
	int	i;

	i = data->map.size;
	data->map.tab = malloc(sizeof(char *) * (data->map.size + 1));
	if (!data->map.tab)
		return (0);
	data->map.tab[i] = '\0';
	while (i >= 0)
	{
		data->map.tab[i] = data->tab[j--];
		jj = get_n(data->map.tab[i]);
		if (jj != -1)
		{
			data->map.tab[i][jj] = '\0';
			// if (data->map.mapwidth < (int)ft_strlen(data->map.tab[i]))
				// data->map.mapwidth = (int)ft_strlen(data->map.tab[i]);
		}
		i--;
	}
	return (1);
}

int	ft_check_map(t_env *data)
{
	int	j;
	int	jj;

	j = 0;
	while (data->tab[j] && (data->tab[j][0] == '\n'
		|| (data->tab[j][0] == 'N' && data->tab[j][1] == 'O') ||
			(data->tab[j][0] == 'S' && data->tab[j][1] == 'O') ||
				(data->tab[j][0] == 'W' && data->tab[j][1] == 'E') ||
					(data->tab[j][0] == 'E' && data->tab[j][1] == 'A') ||
						(data->tab[j][0] == 'C' && data->tab[j][1] == ' ') ||
							(data->tab[j][0] == 'F' && data->tab[j][1] == ' ')))
		j++;
	if (!data->tab[j])
		return (printf("Error\nplease give me a map\n"), 0);
	jj = j;
	while (data->tab[j])
	{
		j++;
		data->map.size++;
	}
	if (ft_verif_bad_elem(data) == 0 || verif_map_lines(data, jj) == 0)
		return (0);
	if (tmp_check_map(data, j, jj) == 0)
		return (0);
	return (verif_map(&data->map));
}

