/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:17:15 by yyuan             #+#    #+#             */
/*   Updated: 2020/01/05 18:20:47 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strchr(char *s, char c)
{
	while(*s)
    {
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return(i);
}

char *ft_strdup(char *s)
{
	int len;
	char *new;

	len = ft_strlen(s) + 1;
	if(!(new = malloc(len * sizeof(char))))
		return (NULL);
	else
		return (ft_strcpy(new,s));
	
}

char	*ft_strcpy(char *d, char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strncpy(char *dest, char *src, int  n)
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

char			*ft_strjoin(char *s1, char *s2)
{
	char *new;

	if (!s1 || !s2
	|| !(new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	ft_strncpy(new, (char *)s1, ft_strlen(s1));
	ft_strcpy(new + ft_strlen(s1), (char *)s2);
	return (new);
}

char			*ft_substr(char *s, int start, int len)
{
	int	l;
	char	*new;

	if (!s || start >= ft_strlen(s))
		return (NULL);
	if (start + len <= ft_strlen(s))
		l = start + len;
	else
		l = ft_strlen(s) - start;
	if (!(new = malloc(l*sizeof(char))))
		return (NULL);
	ft_strncpy(new, &s[start], len);
	return (new);
}

/*void	ft_bzero(static *s[FD_SIZE])
{
	int i;

	while(*s[FD_SIZE])
	{
	i = 0;
		while (s[FD_SIZE][i])
		{
			s[FD_SIZE][i] = 0;
			i++;
		}
	FD_SIZE--;
	}
}*/
int get_next_line(int fd, char **line)
{
	int	ret;
	static	char	*str[FD_SIZE];
	char	buf[BUF_SIZE + 1];
//	char *tmp;
//memset(str,0,sizeof(str));
//printf("%s",*line);
	if (fd<0 || !line)
		return(-1);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		//printf("%s\n",buf);
		buf[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buf);
		else
		{
		str[fd] = ft_strjoin(str[fd],buf);
		}
		if (ft_strchr(str[fd],'\n'))
			break; 
	}
	//if (ret == 0)
	//	return(0);
	int i;

	i = 0;
//printf("out %s\n",str[fd]);
	while (str[fd][i]!='\n')
	{
		i++;
	}
	if(str[fd][i+1]=='\0') {
		*line = ft_strdup("");
		free(str[fd]);
		str[fd] = NULL;
		return 0;
	}
	*line = ft_substr(str[fd],0,i);
	char *tmp = ft_strdup(str[fd] + i + 1);
	free(str[fd]);
	str[fd] = tmp;
	return (1);
}

int main(int argc, char **argv)
{
	int fd;
	int ret;
	int line;
	char *buff;

	line = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &buff)) > 0)
		{
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
			free(buff);
		}
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of file\n");
		close(fd);
	}
return 0;
}












































