/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:07:30 by aclement          #+#    #+#             */
/*   Updated: 2022/12/20 19:09:30 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bis.h"

static	char	*ft_line_builder(char *line, char *buff)
{
	size_t	len;
	size_t	len_line;
	char	*build;

	len_line = ft_strlen_prtctd(line);
	len = 0;
	while (buff[len] != '\n' && buff[len])
		len++;
	if (buff[len] == '\n')
		len++;
	build = (char *)malloc(len_line + len + 1);
	if (!build)
		return (NULL);
	build[len_line + len] = 0;
	ft_memcpy(build, line, len_line);
	ft_memcpy(build + len_line, buff, len);
	ft_buff_adjust(buff, len);
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (build);
}

char	*get_next_line(int fd)
{
	static char	buff[MAXFILES][BUFFER_SIZE + 1];
	char		*line;
	int			oct_readed;

	oct_readed = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	while (!ft_found_nl(line) && oct_readed != 0)
	{
		if (!buff[fd][0])
		{
			oct_readed = read(fd, buff[fd], BUFFER_SIZE);
			buff[fd][oct_readed] = 0;
		}
		line = ft_line_builder(line, buff[fd]);
		if (!line)
			break ;
	}
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
