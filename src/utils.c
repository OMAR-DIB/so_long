/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:43:01 by odib              #+#    #+#             */
/*   Updated: 2024/07/21 13:48:11 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_lines(char *file_name)
{
	int		fd;
	int		lines;
	char	buffer[1];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("can't open file");
		return (0);
	}
	while (read(fd, buffer, 1) > 0)
	{
		if (buffer[0] == '\n')
			lines++;
	}
	close(fd);
	return (lines + 1);
}

int	getmapheight(char *filepath)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		ft_error("error opening file");
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		i++;
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (i + 1);
}

