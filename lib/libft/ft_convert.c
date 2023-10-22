/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:16:46 by aclement          #+#    #+#             */
/*   Updated: 2023/08/22 15:10:45 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mod_c(t_env_printf *var)
{
	char	c;

	if (var->str[var->i] == '%')
		ft_putchar('%');
	else
	{
		c = (char)(va_arg(var->ap, int));
		ft_putchar(c);
	}
	var->i++;
	var->ret = var->ret + 1;
}

void	ft_mod_id(t_env_printf *var, int nb)
{
	int			size;
	long int	nb_cpy;

	size = ft_nblen(nb);
	nb_cpy = nb;
	var->ret = var->ret + size;
	ft_putnbr(nb_cpy);
	var->i++;
}

void	ft_mod_s(t_env_printf *var)
{
	char	*s;
	int		size;
	int		i;

	i = 0;
	s = (char *)(va_arg(var->ap, char *));
	if (s == NULL)
		s = "(null)";
	size = ft_strlen_printf(s);
	var->ret = var->ret + size;
	while (s[i])
		ft_putchar(s[i++]);
	var->i++;
}
