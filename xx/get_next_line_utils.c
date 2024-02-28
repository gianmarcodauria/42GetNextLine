/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:18:41 by gd-auria          #+#    #+#             */
/*   Updated: 2024/02/14 16:41:31 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	strlcatnrem(char *dest, char *src, int flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (src[i])
	{
		dest[i + j] = src[i];
		src[i] = '\0';
		i++;
		if (flag && dest[i + j - 1] == '\n')
			break ;
	}
	if (src[i])
		strlcatnrem(src, src + i, 0);
}

void	*strealloc(char *str, int cycl)
{
	char	*rt;

	if (cycl == 1)
		return (str);
	rt = (char *)ft_calloc(sizeof(char), ((cycl * BUFFER_SIZE) + 1));
	if (str && rt)
	{
		strlcatnrem(rt, str, 0);
		free(str);
	}
	return (rt);
}

char	*hasnewl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (str + i + 1);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*prt;

	prt = malloc(count * size);
	if (prt == NULL)
		return (prt);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *)prt)[i] = '\0';
		i++;
	}
	return (prt);
}
