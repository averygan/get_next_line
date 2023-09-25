/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:30:32 by agan              #+#    #+#             */
/*   Updated: 2023/09/20 11:31:04 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Function to join and realloc current line with buffer
static char	*ft_join(char *res, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(res, buf);
	free(res);
	return (tmp);
}

// Function to extract current line
static char	*ft_clean(char *buf)
{
	char	*nl;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	nl = malloc(sizeof(char *) * (i + 2));
	if (!nl)
		return (NULL);
	if (buf[i] == '\n')
		ft_strlcpy(nl, buf, i + 2);
	else
		ft_strlcpy(nl, buf, i + 1);
	return (nl);
}

// Function to read till \n into buffer
static char	*ft_read(int fd, char *res)
{
	char	*buf;
	int		bytes_read;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (!res)
			res = ft_calloc(1, sizeof(char));
		if (bytes_read == -1)
		{
			free(buf);
			free(res);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		res = ft_join(res, buf);
		if (ft_strchr(res, 10))
			break ;
	}
	free(buf);
	return (res);
}

// Function to clean buffer for next line
static char	*ft_next(char *buf)
{
	int		i;
	char	*line;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	i++;
	ft_strlcpy(line, &buf[i], ft_strlen(buf) - i + 1);
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	nl = ft_clean(buffer);
	buffer = ft_next(buffer);
	return (nl);
}

// int	main(void)
// {
// 	int fd;
// 	char *s;

// 	fd = open("file.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// }
