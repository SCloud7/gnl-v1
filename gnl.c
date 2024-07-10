/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:59:34 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/07/11 01:35:51 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > (unsigned int)ft_strlen(s + start))
		len = (unsigned int)ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*set(char *line)
{
	int		i;
	char	*stock;

	i = 0;
	while (line && line[i] != '\0' && line[i] != '\n')
		i++;
	if (!line || line[i] == 0 || ft_strlen(line) <= (i + 1) || line[1 + i] == 0)
		return (NULL);
	stock = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	if (!stock)
		return (NULL);
	line[i + 1] = '\0';
	// *(line + i + 1) = '\0';
	return (stock);
}

char	*lect(char *stock, int fd)
{
	int		check;
	char	*temp;
	char	*buffer;

	check = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	
	while (ft_strlen(stock) == 0 && read(fd, NULL, 0) == 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check <= 0)
			return (NULL);
		buffer[check] = '\0';
		temp = stock;
		stock = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (!(stock))
		stock = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return ((free(stock)), (stock = NULL));
	line = lect(stock, fd);
	if (!line)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	stock = set(line);
	// if (0 == ft_strlen(stock) && !line)
	// {
	// 	free(stock);
	// 	stock = NULL;
	// 	return (NULL);
	// }
	return (line);
}
