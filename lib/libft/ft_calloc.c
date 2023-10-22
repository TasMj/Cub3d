/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:47:25 by aclement          #+#    #+#             */
/*   Updated: 2023/10/05 14:47:25 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbelem, size_t size)
{
	void	*dest;

	dest = malloc(nbelem * size);
	if (!dest)
		return (NULL);
	ft_memset(dest, 0, nbelem * size);
	return (dest);
}
