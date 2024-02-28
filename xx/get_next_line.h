/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:42:46 by gd-auria          #+#    #+#             */
/*   Updated: 2024/02/14 16:43:52 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

void	strlcatnrem(char *dest, char *src, int flag);
void	*strealloc(char *str, int cycl);
char	*hasnewl(char *str);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);

#endif
