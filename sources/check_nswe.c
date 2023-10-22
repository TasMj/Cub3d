/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nswe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:22:22 by aclement          #+#    #+#             */
/*   Updated: 2023/09/28 17:51:21 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_we(t_env *data)
{
	int	i;	

	i = 0;
	while (i < data->size)
	{
		if (data->tab[i][0] == '\n' || data->tab[i][0] == 'S'
			|| data->tab[i][0] == 'N' || data->tab[i][0] == 'E'
				|| data->tab[i][0] == 'F' || data->tab[i][0] == 'C')
			i++;
		else if (data->tab[i][0] == 'W' && data->tab[i][1] == 'E'
			&& data->tab[i][2] == ' ')
		{
			if (tmp_check_nswe(data, i, 'W') == 1)
				return (1);
			else
				return (0);
		}
		else
		{
			printf("Error\nInvalid char between elements or West is missing\n");
			return (0);
		}
	}
	return (0);
}

int	ft_check_ea(t_env *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		if (data->tab[i][0] == '\n' || data->tab[i][0] == 'S'
			|| data->tab[i][0] == 'W' || data->tab[i][0] == 'N'
				|| data->tab[i][0] == 'F' || data->tab[i][0] == 'C')
			i++;
		else if (data->tab[i][0] == 'E' && data->tab[i][1] == 'A'
			&& data->tab[i][2] == ' ')
		{
			if (tmp_check_nswe(data, i, 'E') == 1)
				return (1);
			else
				return (0);
		}
		else
		{
			printf("Error\nInvalid char between elements or East is missing\n");
			return (0);
		}
	}
	return (0);
}

int	ft_check_so(t_env *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		if (data->tab[i][0] == '\n' || data->tab[i][0] == 'N'
			|| data->tab[i][0] == 'W' || data->tab[i][0] == 'E'
				|| data->tab[i][0] == 'F' || data->tab[i][0] == 'C')
			i++;
		else if (data->tab[i][0] == 'S' && data->tab[i][1] == 'O'
			&& data->tab[i][2] == ' ')
		{
			if (tmp_check_nswe(data, i, 'S') == 1)
				return (1);
			else
				return (0);
		}
		else
		{
			printf("Error\nInvalid char between elements or South is missing\n");
			return (0);
		}
	}
	return (0);
}

int	ft_check_no(t_env *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		if (data->tab[i][0] == '\n' || data->tab[i][0] == 'S'
			|| data->tab[i][0] == 'W' || data->tab[i][0] == 'E'
				|| data->tab[i][0] == 'F' || data->tab[i][0] == 'C')
			i++;
		else if (data->tab[i][0] == 'N' && data->tab[i][1] == 'O'
			&& data->tab[i][2] == ' ')
		{
			if (tmp_check_nswe(data, i, 'N') == 1)
				return (1);
			else
				return (0);
		}
		else
		{
			printf("Error\nInvalid char between elements or North is missing\n");
			return (0);
		}
	}
	return (0);
}
