/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:43:01 by odib              #+#    #+#             */
/*   Updated: 2024/07/25 16:52:52 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

t_var	g_var;

void	initialize(void)
{
	g_var.mlx = NULL;
	g_var.win = NULL;
	g_var.game.count_collec = 0;
	g_var.game.count_steps = 0;
	g_var.map.data = NULL;
	g_var.map.size.height = 0;
	g_var.map.size.width = 0;
	g_var.img.img_ptr = NULL;
	g_var.img.spt_path = "./img/sprite.xpm";
	g_var.img.size.width = 0;
	g_var.img.size.height = 0;
	g_var.img.pos.width = 0;
	g_var.img.pos.height = 0;
	g_var.img.data = NULL;
	// g_var.img.bpp = 0;
	g_var.img.size_line = 0;
}

void	check_arg(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("enter a file");
		exit(1);
	}
	else if(ac > 2)
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

int	count_collec()
{
	int	row;
	int	col;

	row = 0;
	g_var.game.count_collec = 0;
	while (row < g_var.map.size.height)
	{
		col = 0;
		while (col <= g_var.map.size.width)
		{
			if (g_var.map.data[row][col] == 'C')
				g_var.game.count_collec++;
			col++;
		}
		row++;
	}
	return (g_var.game.count_collec);
}

void	print_steps(void)
{
	char	*str;
	char	*convert;

	convert = ft_itoa(g_var.game.count_steps);
	str = ft_strjoin("step ", convert);
	mlx_string_put(g_var.mlx, g_var.win, (g_var.img.pos.width * SPRITE_W) + 10,
	(g_var.img.pos.height * SPRITE_H) + 15, 0x833000, str);
	free(str);
	free(convert);
}

int	key_press(int key)
{
	int	steps;

	steps = g_var.game.count_steps;
	if (key == KEY_ESC)
		free_exit("\e[33m\e[1mGame closed! (X)\e[0m\n");
	else
		moves(key);
	if (steps != g_var.game.count_steps)
		ft_printf("⟹ 📍 Steps: %d\n", g_var.game.count_steps);
	draw_map();
	print_steps();
	return (0);
}

int	main(int argc, char **argv)
{
	initialize();
	check_arg(argc, argv);
	get_map(argv);
	check_map();
	g_var.mlx = mlx_init();
	if (g_var.mlx == NULL)
		perror("Failed to initialize MiniLibX");
	g_var.win = mlx_new_window(g_var.mlx, g_var.map.size.width * SPRITE_W,
			g_var.map.size.height * SPRITE_H, "So long");
	if (g_var.win == NULL)
	{
		free_map();
		perror("Failed to create window");
	}
	init_position();
	draw_map();
	mlx_hook(g_var.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &g_var);
	mlx_hook(g_var.win, X_EVENT_KEY_EXIT, 1L << 0, mlx_close, &g_var);
	mlx_expose_hook(g_var.win, draw_map, &g_var);
	mlx_loop(g_var.mlx);
	return (0);
}