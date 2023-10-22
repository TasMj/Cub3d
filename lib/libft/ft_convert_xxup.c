/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_xxup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:47:11 by aclement          #+#    #+#             */
/*   Updated: 2023/08/22 15:13:58 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mod_xx(t_env_printf *var, unsigned int nb)
{
	int	size;

	if (var->str[var->i] == 'x')
		size = ft_convert_ui_in_hex(nb, BP);
	if (var->str[var->i] == 'X')
		size = ft_convert_ui_in_hex(nb, BG);
	var->ret = var->ret + size;
	var->i++;
}

void	ft_mod_u(t_env_printf *var, unsigned int nb)
{
	int	size;

	size = ft_unsigned_nblen(nb);
	var->ret = var->ret + size;
	ft_unsigned_putnbr(nb);
	var->i++;
}

void	ft_mod_p(t_env_printf *var, unsigned long long int nb)
{
	if (!nb)
	{
		ft_putstr("(nil)");
		var->ret = var->ret + 5;
		var->i++;
		return ;
	}
	ft_putchar('0');
	ft_putchar('x');
	ft_convert_ulli_in_hex(var, nb, BP);
	var->ret = var->ret + 2;
	var->i++;
}
