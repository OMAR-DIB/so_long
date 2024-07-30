/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:04:33 by odib              #+#    #+#             */
/*   Updated: 2024/07/30 17:28:03 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char *str)
{
	int	i;

	i = 0;
	if (g_vr.mlx)
	{
		mlx_destroy_window(g_vr.mlx, g_vr.win);
		mlx_destroy_display(g_vr.mlx);
	}
	free(g_vr.mlx);
	while (i < g_vr.map.size.height)
	{
		free(g_vr.map.data[i]);
		i++;
	}
	free(g_vr.map.data);
	ft_printf("%s", str);
	exit(1);
}

// void	free_exit(char	*sms)
//{
//	ft_printf("%s", sms);
//	free_map();
//	exit(EXIT_FAILURE);
//}

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
	free_map("\e[33m\e[1mGame closed! (X)\e[0m\n");
	return (0);
}
