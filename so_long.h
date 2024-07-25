/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:43:01 by odib              #+#    #+#             */
/*   Updated: 2024/07/25 11:59:05 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MinilibX/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TILE_SIZE 32

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
typedef struct l_position
{
	int			width;
	int			height;
}				t_position;

typedef struct l_map
{
	t_position	size;
	char		**data;
}				t_map;

typedef struct l_img
{
	void		*img_ptr;
	char		*spt_path;
	t_position	size;
	t_position	pos;
	int			size_line;
	//int			bpp;
	void		*data;
}				t_imgg;

typedef struct k_game
{
	int			count_collec;
	int			count_steps;
}				t_game;

typedef struct s_var
{
	void		*mlx;
	void		*win;
	t_game		game;
	t_map		map;
	t_imgg		img;
}				t_var;

extern t_var	g_var;

int		get_height(char *file_name);
void	get_map(char **av);
void	read_map(char *file_name);

#endif