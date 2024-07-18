/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:33:01 by odib              #+#    #+#             */
/*   Updated: 2024/06/27 14:45:06 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			ch;

	ch = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == '\0' && s[i] == ch)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*arr;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	arr = malloc(sizeof(char) * (i + 1));
	if (arr == NULL)
		return (NULL);
	while (j < i)
	{
		arr[j] = s[j];
		j++;
	}
	arr[j] = '\0';
	return (arr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	arr = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (arr == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		arr[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		arr[i] = s2[j];
		i++;
		j++;
	}
	arr[i] = '\0';
	return (arr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	j;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	arr = ft_calloc(len + 1, sizeof(char));
	if (!arr)
		return (NULL);
	j = start;
	while (j - start < len)
	{
		arr[j - start] = s[j];
		j++;
	}
	return (arr);
}
