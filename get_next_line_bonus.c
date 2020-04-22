/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 19:12:31 by yyuan             #+#    #+#             */
/*   Updated: 2020/04/22 19:12:41 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char		*ft_strncpy(char *dest, char *src, int n)
{
	char	*s;
	char	*d;
	int		i;

	s = src;
	d = dest;
	i = 0;
	while (s[i] != '\0' && i < n)
	{
		d[i] = s[i];
		i++;
	}
	while (i < n)
	{
		d[i] = '\0';
		i++;
	}
	return (d);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char *new;

	if (!s1 || !s2
	|| !(new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	ft_strncpy(new, (char *)s1, ft_strlen(s1));
	ft_strcpy(new + ft_strlen(s1), (char *)s2);
	return (new);
}

char		*ft_substr(char *s, size_t start, size_t len)
{
	size_t	l;
	char	*new;

	if (!s || start > ft_strlen(s))
		return (NULL);
	if (start + len <= ft_strlen(s))
		l = start + len + 1;
	else
		l = ft_strlen(s) - start + 1;
	if (start == len)
	{
		new = ft_strdup("");
		return (new);
	}
	if (!(new = malloc(l * sizeof(char))))
		return (NULL);
	new = ft_strncpy(new, &s[start], l - 1);
	new[l - 1] = '\0';
	return (new);
}

int			ft_output(char **str, char **line, int ret, int fd)
{
	int		i;
	char	*tmp;

	if (ret == 0 && str[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	i = ft_strchr(str[fd], '\n');
	if (i != -1)
	{
		*line = ft_substr(str[fd], 0, i);
		tmp = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = tmp;
		return (1);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	static char	*str[FD_SIZE];
	char		*buf;
	char		*t;

	if (!(buf = ft_strnew(BUFFER_SIZE)))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buf);
		else
		{
			t = ft_strjoin(str[fd], buf);
			free(str[fd]);
			str[fd] = t;
		}
		if (ft_strchr(str[fd], '\n') != -1)
			break ;
	}
	free(buf);
	if (!line || fd < 0 || ret < 0 || BUFFER_SIZE <= 0)
		return (-1);
	return (ft_output(str, line, ret, fd));
}
