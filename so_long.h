/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:43:01 by odib              #+#    #+#             */
/*   Updated: 2024/07/30 17:35:14 by odib             ###   ########.fr       */
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
# define SPRITE_H 64
# define SPRITE_W 64
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

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
	// int			bpp;
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

extern t_var	g_vr;

t_position		start_position(void);

void			collectibale_validation(void);
void			read_map(char *file_name);
void			contains_one_exit(void);
void			get_map(char **av);
void			check_map(void);

void			dfs(char **data, t_position start, t_position size,
					int **visited);
void			free_visited(int **visited, t_position size);
void			check_arg(int ac, char **av);
void			is_reachable(int **visited);
void			load_map(int row, int col);
void			has_valid_path(void);
void			is_rectangular(void);
void			free_map(char *str);
void			init_position(void);
void			check_collect(void);
void			walls_valide(void);
void			print_steps(void);
void			initialize(void);
void			move_right(void);
void			move_left(void);
void			move_down(void);
void			moves(int key);
void			move_up(void);

int				get_height(char *file_name);
int				key_press(int key);
int				count_collec(void);
int				is_valid(char c);
int				mlx_close(void);
int				draw_map(void);
#endif