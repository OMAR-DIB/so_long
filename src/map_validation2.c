/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:36:14 by odib              #+#    #+#             */
/*   Updated: 2024/07/30 17:27:52 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// same of get init position
t_position	start_position(void)
{
	t_position	start;
	int			i;
	int			j;

	i = 0;
	start.width = 0;
	start.height = 0;
	while (i < g_vr.map.size.height)
	{
		j = 0;
		while (j < g_vr.map.size.width)
		{
			if (g_vr.map.data[i][j] == 'P')
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
	while (i < g_vr.map.size.height)
	{
		j = 0;
		while (j < g_vr.map.size.width)
		{
			if ((g_vr.map.data[i][j] == 'E' || g_vr.map.data[i][j] == 'C')
				&& !visited[i][j])
			{
				if (g_vr.map.data[i][j] == 'E' || g_vr.map.data[i][j] == 'C')
				{
					free_map("error no path");
					free_visited(visited, g_vr.map.size);
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

	size.width = g_vr.map.size.width;
	size.height = g_vr.map.size.height;
	visited = (int **)malloc(g_vr.map.size.height * sizeof(int *));
	if (!visited)
		free_map("error allocate variable visited");
	i = 0;
	while (i < g_vr.map.size.height)
	{
		visited[i] = (int *)ft_calloc(g_vr.map.size.width, sizeof(int));
		i++;
	}
	start = start_position();
	dfs(g_vr.map.data, start, size, visited);
	is_reachable(visited);
	free_visited(visited, size);
}
