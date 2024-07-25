/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:43:01 by odib              #+#    #+#             */
/*   Updated: 2024/07/25 12:44:11 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_height(char *file_name)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		return (0);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (i);
}

// break statement on extra length
void	read_map(char *file_name)
{
	int		fd;
	char	*lines;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		return (0);
	}
	lines = get_next_line(fd);
	while (lines != NULL)
	{
		g_var.map.data[g_var.map.size.height] = lines;
		i = ft_strlen(lines);
		if (lines[i - 1] == '\n')
		{
			lines[i - 1] = '\0';
			i--;
		}
		if (g_var.map.size.height == 0)
			g_var.map.size.width = i;
		g_var.map.size.height++;
		lines = get_next_line(fd);
	}
	if (lines)
		free(lines);
	close(fd);
}

void	get_map(char **av)
{
	int	num_lines;

	g_var.map.data = NULL;
	g_var.map.size.height = 0;
	g_var.map.size.width = 0;
	num_lines = get_height(av[1]);
	g_var.map.data = (char **)malloc(sizeof(char *) * num_lines);
	if (!g_var.map.data)
	{
		ft_printf("Error allocation data\n");
		exit(1);
	}
	read_map(av[1]);
}
