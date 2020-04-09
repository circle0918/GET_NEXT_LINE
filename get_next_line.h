/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 13:31:24 by yyuan             #+#    #+#             */
/*   Updated: 2020/01/05 18:20:50 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUF_SIZE 4096
# define FD_SIZE 1024

int	ft_strlen(char *s);
char	*ft_strdup(char *s);
char *ft_strcpy(char *d, char *s);
char *ft_strncpy(char *dest, char *src, int c);
char *ft_strjoin(char *s1, char *s2);
char *ft_substr(char *s, int start, int len);
int ft_strchr(char*s, char c);
int		get_next_line(int fd, char **line);

#endif
