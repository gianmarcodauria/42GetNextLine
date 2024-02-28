/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:44:18 by gd-auria          #+#    #+#             */
/*   Updated: 2024/02/14 17:17:09 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];
	int			rdr;
	int			i;

	i = 0;
	rdr = 1;
	line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (rdr >= 0 && hasnewl(line) == 0)
	{
		if (!*buff)
			rdr = read(fd, buff, BUFFER_SIZE);
		if (rdr <= 0)
			break ;
		i++;
		line = strealloc(line, i);
		strlcatnrem(line, buff, 1);
	}
	if (line && *line)
		return (line);
	free(line);
	return (0);
}
