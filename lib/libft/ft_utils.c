/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:56:14 by aclement          #+#    #+#             */
/*   Updated: 2023/08/22 15:12:57 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned_nblen(unsigned int nb)
{
	int	size;

	size = 1;
	while (nb > 9)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

void	ft_putnbr(int nb)
{
	long int	nb_cpy;

	nb_cpy = nb;
	if (nb_cpy < 0)
	{
		ft_putchar('-');
		nb_cpy *= -1;
	}
	if (nb_cpy > 9)
	{
		ft_putnbr(nb_cpy / 10);
		ft_putnbr(nb_cpy % 10);
	}
	if (nb_cpy < 10)
		ft_putchar((nb_cpy % 10) + 48);
}

void	ft_unsigned_putnbr(unsigned int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
}

int	ft_convert_ui_in_hex(unsigned int nb, char *base)
{
	int	size;
	int	i;
	int	tab[35];

	i = 0;
	size = 0;
	if (nb == 0)
	{
		size++;
		ft_putchar('0');
	}
	while (nb)
	{
		tab[i] = nb % 16;
		nb = nb / 16;
		i++;
		size++;
	}
	while (--i >= 0)
		ft_putchar(base[tab[i]]);
	return (size);
}

void	ft_convert_ulli_in_hex(t_env_printf *var, unsigned long long int nb,
			char *base)
{
	int	i;
	int	tab[20];

	i = 0;
	while (nb)
	{
		tab[i] = nb % 16;
		nb = nb / 16;
		i++;
	}
	while (--i >= 0)
	{
		ft_putchar(base[tab[i]]);
		var->ret++;
	}
}
