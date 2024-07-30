/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:58:40 by odib              #+#    #+#             */
/*   Updated: 2024/07/30 17:36:03 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	walls_valide(void)
{
	int	i;

	i = 0;
	while (i < g_vr.map.size.width)
	{
		if (g_vr.map.data[0][i] != '1' || g_vr.map.data[g_vr.map.size.height
			- 1][i] != '1')
		{
			free_map("Invalide map\n");
		}
		i++;
	}
	i = 0;
	while (i < g_vr.map.size.height)
	{
		if (g_vr.map.data[i][0] != '1' || g_vr.map.data[i][g_vr.map.size.width
			- 1] != '1')
		{
			free_map("Invalide map\n");
		}
		i++;
	}
}

void	is_rectangular(void)
{
	int	i;

	i = 0;
	while (i < g_vr.map.size.height)
	{
		if ((int)ft_strlen(g_vr.map.data[i]) != g_vr.map.size.width)
		{
			free_map("not rectangular");
		}
		i++;
	}
}

int	is_valid(char c)
{
	return (c == 'E' || c == 'P' || c == 'C' || c == '1' || c == '0');
}

void	contains_one_exit(void)
{
	int	exit_count;
	int	start_count;
	int	i;
	int	j;

	start_count = 0;
	exit_count = 0;
	i = 0;
	while (i < g_vr.map.size.height)
	{
		j = 0;
		while (j < g_vr.map.size.width)
		{
			if (g_vr.map.data[i][j] == 'E')
				exit_count++;
			if (g_vr.map.data[i][j] == 'P')
				start_count++;
			j++;
		}
		i++;
	}
	if (start_count != 1 || exit_count != 1)
		free_map("error E or P");
}

void	collectibale_validation(void)
{
	int	i;
	int	j;
	int	collect;

	collect = 0;
	i = 0;
	while (i < g_vr.map.size.height)
	{
		j = 0;
		while (j < g_vr.map.size.width)
		{
			if (!is_valid(g_vr.map.data[i][j]))
				free_map("not valid char");
			if (g_vr.map.data[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	if (collect == 0)
		free_map("NO collectible");
	g_vr.game.count_collec = collect;
}

void	check_map(void)
{
	walls_valide();
	is_rectangular();
	collectibale_validation();
	contains_one_exit();
	has_valid_path();
}
