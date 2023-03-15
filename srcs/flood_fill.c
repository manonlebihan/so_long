/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:11:47 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/15 19:14:20 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_map *m, int x, int y)
{
	if (m->map[y][x] != '1')
	{
		if (m->map[y][x] == 'C')
			m->collectible_copy++;
		if (m->map[y][x] == 'E')
			m->exit_copy++;
		m->map[y][x] = '1';
		flood_fill(m, x + 1, y);
		flood_fill(m, x, y - 1);
		flood_fill(m, x - 1, y);
		flood_fill(m, x, y + 1);
		return (1);
	}
	return (0);
}

int	check_flood_fill(t_map map)
{
	t_map	dup;

	if (duplicate_map(map, &dup) == 0)
		return (0);
	dup.collectible_copy = 0;
	dup.exit_copy = 0;
	dup.player_x = map.player_x;
	dup.player_y = map.player_y;
	flood_fill(&dup, dup.player_x, dup.player_y);
	if (dup.collectible_copy != map.collectible || dup.exit_copy != 1)
	{
		free_map(dup);
		return (0);
	}
	free_map(dup);
	return (1);
}
