/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 13:31:24 by yyuan             #+#    #+#             */
/*   Updated: 2020/04/22 14:39:08 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define FD_SIZE 1024

char	*ft_strnew(size_t size);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strcpy(char *d, char *s);
char	*ft_strncpy(char *dest, char *src, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, size_t start, size_t len);
int		ft_strchr(char *s, char c);
int		get_next_line(int fd, char **line);
int		ft_output(char **str, char **line, int ret, int fd);

#endif
