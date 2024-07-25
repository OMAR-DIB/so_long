/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:04:33 by odib              #+#    #+#             */
/*   Updated: 2024/07/25 18:42:30 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(void)
{
	int	i;

	i = 0;
	mlx_destroy_window(g_var.mlx, g_var.win);
	mlx_destroy_display(g_var.mlx);
	free(g_var.mlx);
	while (i < g_var.map.size.height)
	{
		free(g_var.map.data[i]);
		i++;
	}
	free(g_var.map.data);
}

void	free_exit(char	*sms)
{
	ft_printf("%s", sms);
	free_map();
	exit(EXIT_FAILURE);
}

void	free_visited(int **visited, t_position size)
{
	int	i;

	i = 0;
	while (i < size.height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	mlx_close(void)
{
	free_exit("\e[33m\e[1mGame closed! (X)\e[0m\n");
	return (0);
}

