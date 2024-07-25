/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:58:40 by odib              #+#    #+#             */
/*   Updated: 2024/07/25 16:49:31 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	walls_valide(void)
{
	int	i;

	i = 0;
	while (i < g_var.map.size.width)
	{
		if (g_var.map.data[0][i] != '1' || g_var.map.data[g_var.map.size.height
			- 1][i] != '1')
		{
			ft_printf("Invalide map\n");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < g_var.map.size.height)
	{
		if (g_var.map.data[i][0] != '1'
			|| g_var.map.data[i][g_var.map.size.width - 1] != '1')
		{
			ft_printf("Invalide map\n");
			exit(1);
		}
		i++;
	}
}

void	is_rectangular(void)
{
	int	i;

	i = 0;
	while (i < g_var.map.size.height)
	{
		if ((int)ft_strlen(g_var.map.data[i]) != g_var.map.size.width)
		{
			ft_printf("not rectangular");
			exit(1);
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
	while (i < g_var.map.size.height)
	{
		j = 0;
		while (j < g_var.map.size.width)
		{
			if (g_var.map.data[i][j] == 'E')
				exit_count++;
			if (g_var.map.data[i][j] == 'P')
				start_count++;
			j++;
		}
		i++;
	}
	if (start_count != 1 || exit_count != 1)
	{
		ft_printf("error E or P");
		exit(1);
	}
}

void	collectibale_validation(void)
{
	int	i;
	int	j;
	int	collect;

	collect = 0;
	i = 0;
	while (i < g_var.map.size.height)
	{
		j = 0;
		while (j < g_var.map.size.width)
		{
			if (!is_valid(g_var.map.data[i][j]))
			{
				ft_printf("not valid char");
				exit(1);
			}
			if (g_var.map.data[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	if (collect == 0)
	{
		ft_printf("NO collectible");
		exit(1);
	}
	g_var.game.count_collec = collect;
}

void	check_map(void)
{
	walls_valide();
	is_rectangular();
	collectibale_validation();
	contains_one_exit();
	has_valid_path();
}

