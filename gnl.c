/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:24:07 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/07/06 20:16:35 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = c;
	while (*s)
	{
		if (*s == cc)
			return ((char *)s);
		s++;
	}
	if (cc == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*set(char *line)
{
	char	*stock;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == 0)
		return (NULL);
	stock = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (stock == 0)
	{
		free(stock);
		stock = NULL;
	}
	stock[i] = '\0';
	return (stock);
}

char	*rdr(int fd, char *buff, char *left)
{
	int		ret;
	char	*temp;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		else if (ret == 0)
			break ;
		buff[ret] = '\0';
		temp = left;
		left = ft_strjoin(temp, buff);
		free(temp);
		temp = NULL;
	}
	return (left);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*tt;
	static char	*stk;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buff);
		free(stk);
		return (NULL);
	}
	tt = rdr(fd, buff, stk);
	free(buff);
	buff = NULL;
	if (!buff)
		return (NULL);
	stk = set(tt);
	return (tt);
}
