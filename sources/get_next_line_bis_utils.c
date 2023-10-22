/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bis_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:07:19 by aclement          #+#    #+#             */
/*   Updated: 2022/12/20 14:07:20 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bis.h"

int	ft_strlen_prtctd(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s++)
		i++;
	return (i);
}

int	ft_found_nl(char *s)
{
	int		nl;
	char	c;

	nl = 0;
	c = '\n';
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (nl = 1);
		s++;
	}
	return (nl);
}

char	*ft_buff_adjust(char *s, size_t n)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen_prtctd(s + n);
	if (i < l)
		ft_memcpy(s, s + n, l);
	while ((i + l) < BUFFER_SIZE && s[i + l])
	{
		s[i + l] = 0;
		i++;
	}
	return (s);
}
