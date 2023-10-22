/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_norme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:55:34 by aclement          #+#    #+#             */
/*   Updated: 2023/10/18 15:26:20 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*tmp_size_colors(int i, char *line, int nb)
{
	int		j;
	char	*tmp;

	j = 0;
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	if (nb == 1)
	{
		while (j < i - 1)
		{
			tmp[j] = line[j];
			j++;
		}
	}
	else if (nb == 2)
	{
		while (j < i)
		{
			tmp[j] = line[j];
			j++;
		}
	}
	tmp[j] = '\0';
	return (tmp);
}

int	tmp_verif_digit(char *line)
{
	int	i;
	int	vir;
	int	j;

	vir = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if ((i > 0 && line[i] == ',' && ft_isdigit(line[i + 1]) == 1)
			|| ft_isdigit((line[i])) == 1)
		{
			if (line[i] == ',')
			{
				vir++;
				i++;
			}
			j = verif_size_colors(line + i, vir);
			if (j == 0)
				return (printf("Error\ncolors should be between 0 && 255\n"), -1);
			i += j;
		}
		else
			return (printf("Error\nkeep the R,G,B format\n"), -1);
	}
	return (vir);
}

int	tmp_check_fc(t_env *data, int i, char c)
{
	if (check_no_double_elem(data, i, c) == 1)
	{
		if (get_colors(data, data->tab[i] + 1, c) == 1)
			return (1);
		return (0);
	}
	else
		return (0);
}

int	tmp_check_nswe(t_env *data, int i, char c)
{
	if (check_no_double_elem(data, i, c) == 1)
	{
		if (get_texture(data, data->tab[i] + 2, c) == 1)
			return (1);
		return (0);
	}
	else
		return (0);
}

void	mini_split_trim(char *str, t_elem *elem, char fc)
{
	int		i;
	int		j;
	int		f_index;
	char	*tmp;

	i = 0;
	f_index = 0;
	while (str && str[i] != '\0')
	{	
		j = 0;
		tmp = malloc(sizeof(char) * 2000000);
		if (!tmp)
			return ;
		while (str[i] != ',' && str[i] != '\0')
			tmp[j++] = str[i++];
		i++;
		tmp[j] = '\0';
		if (fc == 'f' && f_index < 3)
			elem->floor[f_index++] = ft_atoi(tmp);
		else if (fc == 'c' && f_index < 3)
			elem->ceil[f_index++] = ft_atoi(tmp);
		free(tmp);
	}
}
