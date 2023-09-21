/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:22:57 by agan              #+#    #+#             */
/*   Updated: 2023/09/11 13:22:59 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*tmp;
	size_t i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	else
	{
		tmp = (char *)ptr;
		while (i < (nmemb * size))
		{
			tmp[i] = '\0';
			i++;
		}
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	len = ft_strlen(s1) + ft_strlen (s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str || !s1 || !s2)
		return (NULL);
	while (s1[++i])
	{
		str[j] = s1[i];
		j++;
	}
	i = -1;
	while (s2[++i])
	{
		str[j] = s2[i];
		j++;
	}
	str[j] = '\0';
	return (str);
}

void	*ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = dst;
	if (size == 0)
		return (NULL);
	while (i < size - 1 && src[i])
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0'; 
	return (tmp);
}
