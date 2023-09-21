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

char	*ft_join(char *res, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(res, buf);
	free(res);
	return (tmp);
}

char	*ft_clean(char *buf)
{
	char	*nl;
	int i;

	i = 0;
	// If buffer is an empty line
	if (!buf[i])
		return (NULL);
	// Get number of chars until new line found or eol
	while (buf[i] && buf[i] != '\n')
		i++;
	// Malloc size of new line + space for \n and 0
	nl = malloc(sizeof(char *) * (i + 2));
	if (!nl)
		return (NULL);
	// Copy size of nl
	if (buf[i] == '\n')
		ft_strlcpy(nl, buf, i + 2);
	else
		ft_strlcpy(nl, buf, i + 1);
	// Return nl
	return (nl);
}

// Function to read till \n into buffer
char	*ft_read(int fd, char *res)
{
	char	*buf;
	int		bytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	// Start reading into buffer
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			if (res)
				free(res);
			return (NULL);
		}
		if (!res)
			res = ft_calloc(1, 1);
		buf[bytes_read] = '\0';
		// Join current buf with res
		res = ft_join(res, buf);
		//printf("bytes read is %i, res is %s\n", bytes_read, res);
		if (ft_strchr(res, 10))
			break ;
	}
	free(buf);
	return (res);
}

// Clean buffer for next line
char	*ft_next(char *buf)
{
	int i;
	int j;
	char *line;

	j = 0;
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	// Malloc length of line after nl
	line = malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	// Copy buffer after \n
	i++;
	while (buf[i])
		line[j++] = buf[i++];
	line[j] = '\0';
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*nl;

	// Error handling
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	// Read into buffer
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	// Clean buffer to get nl
	nl = ft_clean(buffer);
	//printf("buffer is %s", nl);
	// Clean buffer for next call
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