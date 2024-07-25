/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:36:14 by odib              #+#    #+#             */
/*   Updated: 2024/07/25 18:44:12 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//same of get init position
t_position	start_position(void)
{
	t_position	start;
	int	i;
	int	j;

	i = 0;
	start.width = 0;
	start.height = 0;
	while (i < g_var.map.size.height)
	{
		j = 0;
		while (j < g_var.map.size.width)
		{
			if (g_var.map.data[i][j] == 'P')
			{
				start.width = j;
				start.height = i;
			}
			j++;
		}
		i++;
	}
	return (start);
}

void	is_reachable(int **visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_var.map.size.height)
	{
		j = 0;
		while (j < g_var.map.size.width)
		{
			if ((g_var.map.data[i][j] == 'E' || g_var.map.data[i][j] == 'C')
			&& !visited[i][j])
			{
				if (g_var.map.data[i][j] == 'E')
				{
					ft_printf("error no path");
					exit(1);
				}
				if (g_var.map.data[i][j] == 'C')
				{
					ft_printf("error no path");
					exit(1);
				}
				break ;
			}
			j++;
		}
		i++;
	}
}

void	has_valid_path(void)
{
	int			**visited;
	int			i;
	t_position	start;
	t_position	size;

	size.width = g_var.map.size.width;
	size.height = g_var.map.size.height;
	visited = (int **)malloc(g_var.map.size.height * sizeof(int *));
	if (!visited)
		free_map();
	i = 0;
	while (i < g_var.map.size.height)
	{
		visited[i] = (int *)ft_calloc(g_var.map.size.width, sizeof(int));
		i++;
	}
	start = start_position();
	dfs(g_var.map.data, start, size, visited);
	is_reachable(visited);
	free_visited(visited, size);
}
