/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:34:54 by odib              #+#    #+#             */
/*   Updated: 2024/06/14 17:56:17 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	str_len(char const *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t		dest_len;
	size_t		total_len;
	const char	*s;

	if ((!dest || !src) && !n)
		return (0);
	s = src;
	dest_len = 0;
	while (*(dest + dest_len) && dest_len < n)
		dest_len++;
	if (dest_len < n)
		total_len = dest_len + str_len(s);
	else
		return (n + str_len(s));
	while (*s && (dest_len + 1) < n)
	{
		*(dest + dest_len) = *s++;
		dest_len++;
	}
	*(dest + dest_len) = '\0';
	return (total_len);
}
