/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:54:11 by odib              #+#    #+#             */
/*   Updated: 2024/07/30 17:28:12 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	dfs(char **data, t_position start, t_position size, int **visited)
{
	t_position	next_positions[4];

	next_positions[0].width = start.width;
	next_positions[0].height = start.height + 1;
	next_positions[1].width = start.width;
	next_positions[1].height = start.height - 1;
	next_positions[2].width = start.width + 1;
	next_positions[2].height = start.height;
	next_positions[3].width = start.width - 1;
	next_positions[3].height = start.height;
	if (start.height < 0 || start.height >= size.height || start.width < 0
		|| start.width >= size.width
		|| data[start.height][start.width] == '1'
		|| visited[start.height][start.width])
		return ;
	visited[start.height][start.width] = 1;
	dfs(data, next_positions[0], size, visited);
	dfs(data, next_positions[1], size, visited);
	dfs(data, next_positions[2], size, visited);
	dfs(data, next_positions[3], size, visited);
}
