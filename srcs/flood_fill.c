/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:10:24 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/08 20:16:10 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* int	check_player(t_map *m, int x, int y)
{
	if (m->map_copy[x][y] == 'P' &&
		(m->map_copy[x + 1][y] == 'C' || m->map_copy[x + 1][y] == '0'
		|| m->map_copy[x - 1][y] == 'C' || m->map_copy[x - 1][y] == '0'
		|| m->map_copy[x][y + 1] == 'C' || m->map_copy[x][y + 1] == '0'
		|| m->map_copy[x][y - 1] == 'C' || m->map_copy[x][y - 1] == '0'))
	{
		return (1);
	}
	return (0);
}

void	around_player(t_map *m, int x, int y)
{
	if (m->map_copy[x][y] == 'C' || m->map_copy[x][y] == '0')
	{
		if (m->map_copy[x][y] == 'C')
			m->collectible_copy--;
		m->map_copy[x][y] = 'P';
	}
}

int	check_exit(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	while (m->map_copy[x])
	{
		y = 0;
		while (m->map_copy[x][y])
		{
			if ((m->map_copy[x][y] == 'E' && m->map_copy[x + 1][y] == 'P')
			|| (m->map_copy[x][y] == 'E' && m->map_copy[x - 1][y] == 'P')
			|| (m->map_copy[x][y] == 'E' && m->map_copy[x][y + 1] == 'P')
			|| (m->map_copy[x][y] == 'E' && m->map_copy[x][y - 1] == 'P'))
			{
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	flood_fill(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	m->collectible_copy = m->collectible;
	while (x < m->nb_lines)
	{
		y = 0;
		while (m->map_copy[x][y])
		{
			if (check_player(m, x, y))
			{
				around_player(m, x + 1, y);
				around_player(m, x - 1, y);
				around_player(m, x, y + 1);
				around_player(m, x, y - 1);
				x = 0;
			}
			y++;
		}
		x++;
	}
	if (m->collectible_copy == 0 && check_exit(m))
		return (1);
	return (0);
} */

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
