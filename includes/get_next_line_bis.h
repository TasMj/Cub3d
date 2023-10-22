/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bis.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:11:05 by aclement          #+#    #+#             */
/*   Updated: 2022/12/20 19:29:52 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BIS_H
# define GET_NEXT_LINE_BIS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define MAXFILES FOPEN_MAX

# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

char	*get_next_line(int fd);
char	*ft_buff_adjust(char *s, size_t n);

int		ft_found_nl(char *s);
int		ft_strlen_prtctd(char *s);

#endif