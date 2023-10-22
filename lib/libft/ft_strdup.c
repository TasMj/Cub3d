/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:46:54 by aclement          #+#    #+#             */
/*   Updated: 2023/09/27 16:49:33 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newchaine;
	int		i;

	i = 0;
	newchaine = malloc(ft_strlen(s) + 1);
	if (!newchaine)
		return (NULL);
	while (s[i])
	{
		newchaine[i] = s[i];
		i++;
	}
	newchaine[i] = '\0';
	return (newchaine);
}
