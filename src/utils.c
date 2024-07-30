/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:43:01 by odib              #+#    #+#             */
/*   Updated: 2024/07/30 17:39:01 by odib             ###   ########.fr       */
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
		exit(1);
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

int	count_collec(void)
{
	int	row;
	int	col;

	row = 0;
	g_vr.game.count_collec = 0;
	while (row < g_vr.map.size.height)
	{
		col = 0;
		while (col <= g_vr.map.size.width)
		{
			if (g_vr.map.data[row][col] == 'C')
				g_vr.game.count_collec++;
			col++;
		}
		row++;
	}
	return (g_vr.game.count_collec);
}

void	print_steps(void)
{
	char	*str;
	char	*convert;

	convert = ft_itoa(g_vr.game.count_steps);
	str = ft_strjoin("step ", convert);
	mlx_string_put(g_vr.mlx, g_vr.win, (g_vr.img.pos.width * SPRITE_W) + 10,
		(g_vr.img.pos.height * SPRITE_H) + 15, 0x833000, str);
	free(str);
	free(convert);
}

int	key_press(int key)
{
	int	steps;

	steps = g_vr.game.count_steps;
	if (key == KEY_ESC)
		free_map("\e[33m\e[1mGame closed! (X)\e[0m\n");
	else
		moves(key);
	if (steps != g_vr.game.count_steps)
		ft_printf("⟹ 📍 Steps: %d\n", g_vr.game.count_steps);
	draw_map();
	print_steps();
	return (0);
}

void	check_collect(void)
{
	if (count_collec() == 0)
		free_map("\e[32m\e[5m\e[1m🎉 CONGRATULATIONS 🎉\n!!!! You WON !!!!\e[0m\n");
	else
		ft_printf("\e[35m\e[1m ⚠️  Please, collect all the balls!!!\e[0m\n");
}