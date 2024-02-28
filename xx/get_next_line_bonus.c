/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:21:05 by gd-auria          #+#    #+#             */
/*   Updated: 2024/02/16 15:28:07 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1];
	int			rdr;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	rdr = 1;
	line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (rdr >= 0 && hasnewl(line) == 0)
	{
		if (!*buff[fd])
			rdr = read(fd, buff[fd], BUFFER_SIZE);
		if (rdr <= 0)
			break ;
		i++;
		line = strealloc(line, i);
		strlcatnrem(line, buff[fd], 1);
	}
	if (line && *line)
		return (line);
	free(line);
	return (0);
}
