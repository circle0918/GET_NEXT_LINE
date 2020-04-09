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
memset(str,0,sizeof(str));
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
	int i;

	i = 0;
	while (str[fd][i]!='\n')
		i++;
	*line = ft_substr(str[fd],0,i+1);
//printf("%s",*line);
	if(str[fd]+i+1)
		str[fd] = str[fd]+ i + 1;
return (1);
}
/*
//int main( int ac, char **av)
//{
//char  *line;
//int   fd1;
//fd1 = open(av[1], O_RDONLY);
// // fd2 = open(av[2], O_RDONLY);
//  get_next_line(fd1, &line);
//   printf("%s\n", line);
//
//  get_next_line(fd1, &line);
//
//   printf("%s\n", line);
//  get_next_line(fd1, &line);
//   printf("%s\n", line);
//
//  get_next_line(fd1, &line);
//   printf("%s\n", line);
//  get_next_line(fd1, &line);
//   printf("%s\n", line);
//  get_next_line(fd1, &line);
//   printf("%s\n", line);
//  get_next_line(fd1, &line);
  // printf("%s\n", line);
  //get_next_line(fd1, &line);
  //get_next_line(fd1, &line);
  //get_next_line(fd1, &line);
  //get_next_line(fd1, &line);
  //get_next_line(fd1, &line);
  //get_next_line(fd1, &line);
  //get_next_line(fd1, &line);
  //get_next_line(fd1, &line);
  //get_next_line(fd1, &line);
  //get_next_line(fd1, &line);
  //get_next_line(fd1, &line);
  //get_next_line(fd1, &line);
  //get_next_line(fd1, &line);
//////
//  get_next_line(fd1, &line);
////   printf("%s\n", line);
////
////char *s = "hello";
////int i = 3;;
////int len = 5;
////printf("%s",ft_substr(s,i,len));
////
return 0;

}*/
