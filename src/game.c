/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:22:25 by odib              #+#    #+#             */
/*   Updated: 2024/07/30 17:28:17 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_position(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_vr.map.size.height)
	{
		j = 0;
		while (j < g_vr.map.size.width)
		{
			if (g_vr.map.data[i][j] == 'P')
			{
				g_vr.img.pos.width = j;
				g_vr.img.pos.height = i;
			}
			j++;
		}
		i++;
	}
}
