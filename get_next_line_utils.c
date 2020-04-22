/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 11:40:53 by yyuan             #+#    #+#             */
/*   Updated: 2020/04/22 17:03:18 by yyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr(char *s, char c)
{
	char *tmp;

	tmp = s;
	while (s && *s)
	{
		if (*s == c)
		{
			return (s - tmp);
		}
		s++;
	}
	return (-1);
}

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

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

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*new;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) + 1;
	if (!(new = malloc(len * sizeof(char))))
		return (NULL);
	else
		return (ft_strcpy(new, s));
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
