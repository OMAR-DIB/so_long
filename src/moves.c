/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:51:02 by odib              #+#    #+#             */
/*   Updated: 2024/07/30 17:29:47 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_left(void)
{
	g_vr.map.data[g_vr.img.pos.height][g_vr.img.pos.width] = '0';
	g_vr.img.pos.width -= 1;
	g_vr.map.data[g_vr.img.pos.height][g_vr.img.pos.width] = 'P';
	g_vr.game.count_steps++;
	g_vr.img.spt_path = "./img/sprite2.xpm";
}

void	move_right(void)
{
	g_vr.map.data[g_vr.img.pos.height][g_vr.img.pos.width] = '0';
	g_vr.img.pos.width += 1;
	g_vr.map.data[g_vr.img.pos.height][g_vr.img.pos.width] = 'P';
	g_vr.game.count_steps++;
	g_vr.img.spt_path = "./img/sprite1.xpm";
}

void	move_up(void)
{
	g_vr.map.data[g_vr.img.pos.height][g_vr.img.pos.width] = '0';
	g_vr.img.pos.height -= 1;
	g_vr.map.data[g_vr.img.pos.height][g_vr.img.pos.width] = 'P';
	g_vr.game.count_steps++;
	g_vr.img.spt_path = "./img/sprite1.xpm";
}

void	move_down(void)
{
	g_vr.map.data[g_vr.img.pos.height][g_vr.img.pos.width] = '0';
	g_vr.img.pos.height += 1;
	g_vr.map.data[g_vr.img.pos.height][g_vr.img.pos.width] = 'P';
	g_vr.game.count_steps++;
	g_vr.img.spt_path = "./img/sprite1.xpm";
}

void	moves(int key)
{
	if ((key == KEY_A)
		&& (g_vr.map.data[g_vr.img.pos.height][g_vr.img.pos.width - 1] == 'E'))
		check_collect();
	else if ((key == KEY_A)
		&& (g_vr.map.data[g_vr.img.pos.height][g_vr.img.pos.width - 1] != '1'))
		move_left();
	if ((key == KEY_D)
		&& (g_vr.map.data[g_vr.img.pos.height][g_vr.img.pos.width + 1] == 'E'))
		check_collect();
	else if ((key == KEY_D)
		&& (g_vr.map.data[g_vr.img.pos.height][g_vr.img.pos.width + 1] != '1'))
		move_right();
	if ((key == KEY_S)
		&& (g_vr.map.data[g_vr.img.pos.height + 1][g_vr.img.pos.width] == 'E'))
		check_collect();
	else if ((key == KEY_S)
		&& (g_vr.map.data[g_vr.img.pos.height + 1][g_vr.img.pos.width] != '1'))
		move_down();
	if ((key == KEY_W)
		&& (g_vr.map.data[g_vr.img.pos.height - 1][g_vr.img.pos.width] == 'E'))
		check_collect();
	else if ((key == KEY_W)
		&& (g_vr.map.data[g_vr.img.pos.height - 1][g_vr.img.pos.width] != '1'))
		move_up();
}
