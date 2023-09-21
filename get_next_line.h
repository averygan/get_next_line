/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:23:07 by agan              #+#    #+#             */
/*   Updated: 2023/09/11 13:25:59 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

/* Get next line */
char	*ft_join(char *res, char *buf);
char	*ft_clean(char *buf);
char	*ft_next(char *buf);
char	*get_next_line(int fd);

/* Helper functions */
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_strlcpy(char *dst, const char *src, size_t size);

#endif
