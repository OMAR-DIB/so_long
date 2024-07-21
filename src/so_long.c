/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:43:01 by odib              #+#    #+#             */
/*   Updated: 2024/07/21 13:55:26 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%d", count_lines(argv[1]));
		printf("%d", getmapheight(argv[1]));
	}
	return 0;
}