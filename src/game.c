/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:22:25 by odib              #+#    #+#             */
/*   Updated: 2024/07/25 15:24:49 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_position(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_var.map.size.height)
	{
		j = 0;
		while (j < g_var.map.size.width)
		{
			if (g_var.map.data[i][j] == 'P')
			{
				g_var.img.pos.width = j;
				g_var.img.pos.height = i;
			}
			j++;
		}
		i++;
	}
}

