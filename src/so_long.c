/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:43:01 by odib              #+#    #+#             */
/*   Updated: 2024/07/30 17:39:07 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_var	g_vr;

void	check_arg(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("enter a file");
		exit(1);
	}
	else if (ac > 2)
	{
		ft_printf("multi arguent");
		exit(1);
	}
	else
	{
		if (ft_strstr(av[1], ".ber") == NULL)
		{
			ft_printf("your file should be <.ber>");
			exit(1);
		}
	}
}

int	main(int argc, char **argv)
{
	initialize();
	check_arg(argc, argv);
	get_map(argv);
	check_map();
	g_vr.mlx = mlx_init();
	if (g_vr.mlx == NULL)
		perror("Failed to initialize MiniLibX");
	g_vr.win = mlx_new_window(g_vr.mlx, g_vr.map.size.width * SPRITE_W,
			g_vr.map.size.height * SPRITE_H, "So long");
	if (g_vr.win == NULL)
	{
		free_map("");
		perror("Failed to create window");
	}
	init_position();
	draw_map();
	mlx_hook(g_vr.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &g_vr);
	mlx_hook(g_vr.win, X_EVENT_KEY_EXIT, 1L << 0, mlx_close, &g_vr);
	mlx_expose_hook(g_vr.win, draw_map, &g_vr);
	mlx_loop(g_vr.mlx);
	return (0);
}
