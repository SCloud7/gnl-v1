/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:26:39 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/07/06 18:27:18 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ss;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ss = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), (sizeof(char)));
	if (ss == NULL)
		return (NULL);
	while (s1[i])
	{
		ss[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ss[i + j] = s2[j];
		j++;
	}
	return (ss);
}

char	*ft_strdup(const char *s)
{
	char	*c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
		j++;
	c = malloc(j * sizeof(const char) + 1);
	if (c == NULL)
		return (NULL);
	while (s[i])
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rep;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > (unsigned int)ft_strlen(s + start))
		len = (unsigned int)ft_strlen(s + start);
	rep = ft_calloc(len + 1, sizeof(char));
	if (!rep)
		return (NULL);
	while (i < len)
	{
		rep[i] = s[i + start];
		i++;
	}
	return (rep);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = (NULL);
	p = malloc(nmemb * (size));
	if (p == NULL)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	char	*ss;
	size_t	i;

	ss = (char *)s;
	i = 0;
	while (i < n)
	{
		ss[i] = 0;
		i++;
	}
}
