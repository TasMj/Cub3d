/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:44:23 by aclement          #+#    #+#             */
/*   Updated: 2023/08/22 15:02:00 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_firstparse(t_env_printf *var)
{
	while (var->str && var->str[var->i])
	{
		while (var->str[var->i] && var->str[var->i] != '%')
		{
			ft_putchar(var->str[var->i++]);
			var->ret++;
		}
		if (var->str[var->i] == '%')
		{
			var->i++;
			ft_parsemodulo(var);
		}
	}
}

void	ft_parsemodulo(t_env_printf *var)
{
	while (var->str[var->i])
	{
		if ((ft_c_in_str(CONVERTS, var->str[var->i])) != 1)
			var->i++;
		else
		{
			ft_choose_conv(var);
			break ;
		}
	}
	if (!(var->str[var->i]))
		return ;
}

void	ft_choose_conv(t_env_printf *var)
{
	if (var->str[var->i] == 'c' || var->str[var->i] == '%')
		ft_mod_c(var);
	else if (var->str[var->i] == 'd' || var->str[var->i] == 'i')
		ft_mod_id(var, va_arg(var->ap, int));
	else if (var->str[var->i] == 'x' || var->str[var->i] == 'X')
		ft_mod_xx(var, va_arg(var->ap, unsigned int));
	else if (var->str[var->i] == 'u')
		ft_mod_u(var, va_arg(var->ap, unsigned int));
	else if (var->str[var->i] == 's')
		ft_mod_s(var);
	else if (var->str[var->i] == 'p')
		ft_mod_p(var, va_arg(var->ap, unsigned long long int));
}
