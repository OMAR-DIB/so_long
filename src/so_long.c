/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:43:01 by odib              #+#    #+#             */
/*   Updated: 2024/07/25 11:56:08 by odib             ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	initialize();
	check_arg(argc, argv);
	get_map(argv);
	return (0);
}