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
 char        *ft_strnew(size_t size)
 {
     char        *s;
     size_t      i;
 
     if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
         return (0);
     if ((size + 1) > 0)
     {
         i = 0;
         while (i < (size + 1))
         {
             s[i] = 0;
             i++;
         }
     }
     return (s);
 }
char *ft_strdup(char *s)
{
	size_t len;
	char *new;
	if (s==NULL)
		return(NULL);
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
#if 1
char			*ft_substr(char *s, size_t start, size_t len)
{
	size_t	l;
	char	*new;

	if (!s || start > ft_strlen(s))
		return (NULL);
	if (start + len <= ft_strlen(s))
		l = start + len + 1;
	else
		l = ft_strlen(s) - start + 1;
	
	if (start==len)
	{
		new = ft_strdup("");
		return(new);
	}
	if (!(new = malloc(l*sizeof(char))))
		return (NULL);
size_t i = 0;
	new[l-1]='\0';
	while(i<l-1){
	new[i]=s[start];
	i++;
	start++;
	}
	//ft_strncpy(new, &s[start], l-1);
	return (new);
}
#else
void	ft_bzero(void *s, size_t n)
{
	unsigned char *str;

	str = s;
	while (n)
	{
		*str = 0;
		str++;
		n--;
	}
}
static char		*ft_strnew(size_t size)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}


char			*ft_substr(char  *s, int start, int len)
{
	int	i;
	char	*tab;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		if (!(tab = ft_strnew(1)))
			return (0);
		return (tab);
	}
	i = 0;
	while (s[start + i] && i < len)
		i++;
	if (!(tab = ft_strnew(i)))
		return (0);
	ft_strncpy(tab, &s[start], len);
	return (tab);
}
#endif

int get_next_line(int fd, char **line)
{
	int	ret;
	int i;
	static	char	*str[FD_SIZE];
	char	*buf;
//	char *tmp;
//memset(str,0,sizeof(str));
//printf("%s",*line);
if (!(buf = ft_strnew(BUFFER_SIZE)))
	return(-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		//printf("%s\n",buf);
		buf[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buf);
		else
		{
			char * t = ft_strjoin(str[fd],buf);
			free(str[fd]);
			str[fd] = t;
		}
		if (ft_strchr(str[fd],'\n'))
			break; 
	}
	free(buf);	
	if (!line || fd<0 || ret<0 || BUFFER_SIZE<=0)
		return(-1);
	if (ret == 0 && str[fd]==NULL)
	{
		*line = ft_strdup("");	
		return(0);
	}
	if (ft_strchr(str[fd],'\n'))
	{
		i = 0;
		while (str[fd][i]!='\n')
			i++;
		*line = ft_substr(str[fd],0,i);
		
		char *tmp = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = tmp;
		return (1);
	}
	else
	{
		i = 0;
		while (str[fd][i]!='\0')
			i++;
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd]=NULL;
		return (0);
	}
}
#if 0
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
		if(buff)
			free(buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of file\n");
		close(fd);
	}
return 0;
}
#endif
