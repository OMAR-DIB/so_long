/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:51:02 by odib              #+#    #+#             */
/*   Updated: 2024/07/25 18:40:34 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_left(void)
{
	g_var.map.data[g_var.img.pos.height][g_var.img.pos.width] = '0';
	g_var.img.pos.width -= 1;
	g_var.map.data[g_var.img.pos.height][g_var.img.pos.width] = 'P';
	g_var.game.count_steps++;
	g_var.img.spt_path = "./img/sprite2.xpm";
}

void	move_right(void)
{
	g_var.map.data[g_var.img.pos.height][g_var.img.pos.width] = '0';
	g_var.img.pos.width += 1;
	g_var.map.data[g_var.img.pos.height][g_var.img.pos.width] = 'P';
	g_var.game.count_steps++;
	g_var.img.spt_path = "./img/sprite1.xpm";
}

void	move_up(void)
{
	g_var.map.data[g_var.img.pos.height][g_var.img.pos.width] = '0';
	g_var.img.pos.height -= 1;
	g_var.map.data[g_var.img.pos.height][g_var.img.pos.width] = 'P';
	g_var.game.count_steps++;
	g_var.img.spt_path = "./img/sprite1.xpm";
}

void	move_down(void)
{
	g_var.map.data[g_var.img.pos.height][g_var.img.pos.width] = '0';
	g_var.img.pos.height += 1;
	g_var.map.data[g_var.img.pos.height][g_var.img.pos.width] = 'P';
	g_var.game.count_steps++;
	g_var.img.spt_path = "./img/sprite1.xpm";
}

void	check_collect(void)
{
	if (count_collec() == 0)
		free_exit("\e[32m\e[5m\e[1m🎉 CONGRATULATIONS 🎉\n!!!! You WON !!!!\e[0m\n");
	else
		ft_printf("\e[35m\e[1m ⚠️  Please, collect all the balls!!!\e[0m\n");
}

//try to change
void	moves(int key)
{
	if ((key == KEY_A)
		&& (g_var.map.data[g_var.img.pos.height][g_var.img.pos.width - 1] == 'E'))
		check_collect();
	else if ((key == KEY_A)
		&& (g_var.map.data[g_var.img.pos.height][g_var.img.pos.width - 1] != '1'))
		move_left();
	if ((key == KEY_D)
		&& (g_var.map.data[g_var.img.pos.height][g_var.img.pos.width + 1] == 'E'))
		check_collect();
	else if ((key == KEY_D)
		&& (g_var.map.data[g_var.img.pos.height][g_var.img.pos.width + 1] != '1'))
		move_right();
	if ((key == KEY_S)
		&& (g_var.map.data[g_var.img.pos.height + 1][g_var.img.pos.width] == 'E'))
		check_collect();
	else if ((key == KEY_S)
		&& (g_var.map.data[g_var.img.pos.height + 1][g_var.img.pos.width] != '1'))
		move_down();
	if ((key == KEY_W)
		&& (g_var.map.data[g_var.img.pos.height - 1][g_var.img.pos.width] == 'E'))
		check_collect();
	else if ((key == KEY_W)
		&& (g_var.map.data[g_var.img.pos.height - 1][g_var.img.pos.width] != '1'))
		move_up();
}