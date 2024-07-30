/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:04:47 by odib              #+#    #+#             */
/*   Updated: 2024/07/30 17:38:35 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize(void)
{
	g_vr.mlx = NULL;
	g_vr.win = NULL;
	g_vr.game.count_collec = 0;
	g_vr.game.count_steps = 0;
	g_vr.map.data = NULL;
	g_vr.map.size.height = 0;
	g_vr.map.size.width = 0;
	g_vr.img.img_ptr = NULL;
	g_vr.img.spt_path = "./img/sprite.xpm";
	g_vr.img.size.width = 0;
	g_vr.img.size.height = 0;
	g_vr.img.pos.width = 0;
	g_vr.img.pos.height = 0;
	g_vr.img.data = NULL;
	g_vr.img.size_line = 0;
}



// break statement on extra length
void	read_map(char *file_name)
{
	int		fd;
	char	*lines;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		free_map("Error opening file\n");
	lines = get_next_line(fd);
	while (lines != NULL)
	{
		i = ft_strlen(lines);
		if (lines[i - 1] == '\n')
		{
			lines[i - 1] = '\0';
			i--;
		}
		g_vr.map.data[g_vr.map.size.height] = ft_strdup(lines);
		if (g_vr.map.size.height == 0)
			g_vr.map.size.width = i;
		g_vr.map.size.height++;
		free(lines);
		lines = get_next_line(fd);
	}
	close(fd);
}

void	get_map(char **av)
{
	int	num_lines;

	g_vr.map.data = NULL;
	g_vr.map.size.height = 0;
	g_vr.map.size.width = 0;
	num_lines = get_height(av[1]);
	if (!num_lines)
		free_map("error aloocation\n");
	g_vr.map.data = (char **)malloc(sizeof(char *) * num_lines);
	if (!g_vr.map.data)
		free_map("Error allocation data\n");
	read_map(av[1]);
}

void	load_map(int row, int col)
{
	if (g_vr.map.data[row][col] == '1')
		g_vr.img.img_ptr = mlx_xpm_file_to_image(g_vr.mlx, "./img/wall.xpm",
				&g_vr.img.size.width, &g_vr.img.size.height);
	else if (g_vr.map.data[row][col] == '0')
		g_vr.img.img_ptr = mlx_xpm_file_to_image(g_vr.mlx, "./img/floor.xpm",
				&g_vr.img.size.width, &g_vr.img.size.height);
	else if (g_vr.map.data[row][col] == 'E')
		g_vr.img.img_ptr = mlx_xpm_file_to_image(g_vr.mlx, "./img/exit.xpm",
				&g_vr.img.size.width, &g_vr.img.size.height);
	else if (g_vr.map.data[row][col] == 'C')
		g_vr.img.img_ptr = mlx_xpm_file_to_image(g_vr.mlx,
				"./img/drgn_ball.xpm", &g_vr.img.size.width,
				&g_vr.img.size.height);
	else if (g_vr.map.data[row][col] == 'P')
		g_vr.img.img_ptr = mlx_xpm_file_to_image(g_vr.mlx, g_vr.img.spt_path,
				&g_vr.img.size.width, &g_vr.img.size.height);
	mlx_put_image_to_window(g_vr.mlx, g_vr.win, g_vr.img.img_ptr, SPRITE_W
		* col, SPRITE_H * row);
	mlx_destroy_image(g_vr.mlx, g_vr.img.img_ptr);
}

int	draw_map(void)
{
	int	row;
	int	col;

	row = 0;
	while (row < g_vr.map.size.height)
	{
		col = 0;
		while (col < g_vr.map.size.width)
		{
			load_map(row, col);
			col++;
		}
		row++;
	}
	return (0);
}

