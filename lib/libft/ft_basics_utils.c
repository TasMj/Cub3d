/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:17:16 by aclement          #+#    #+#             */
/*   Updated: 2023/08/22 15:04:16 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_c_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		else
			i++;
	}
	return (0);
}

int	ft_strlen_printf(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int	ft_nblen(long int nb)
{
	int	size;

	size = 1;
	if (nb < 0)
	{
		size++;
		nb = nb * -1;
	}
	while (nb > 9)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}
