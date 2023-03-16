/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_char_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:19:33 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/16 11:19:34 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

void	assign_x_y(t_map *m, char c, int x, int y)
{
	if (c == 'P')
	{
		m->player_x = x;
		m->player_y = y;
	}
	else if (c == 'E')
	{
		m->exit_x = x;
		m->exit_y = y;
	}
}

void	assign_char_up(t_solong *sl)
{
	if (sl->map.player_y == sl->map.exit_y
		&& sl->map.player_x == sl->map.exit_x)
	{
				sl->map.map[sl->map.player_y - 1][sl->map.player_x] = 'P';
				sl->map.map[sl->map.player_y][sl->map.player_x] = 'E';
	}
	else
	{
		sl->map.map[sl->map.player_y - 1][sl->map.player_x] = 'P';
		sl->map.map[sl->map.player_y][sl->map.player_x] = '0';
	}
}

void	assign_char_down(t_solong *sl)
{
	if (sl->map.player_y == sl->map.exit_y
		&& sl->map.player_x == sl->map.exit_x)
	{
		sl->map.map[sl->map.player_y + 1][sl->map.player_x] = 'P';
		sl->map.map[sl->map.player_y][sl->map.player_x] = 'E';
	}
	else
	{
		sl->map.map[sl->map.player_y + 1][sl->map.player_x] = 'P';
		sl->map.map[sl->map.player_y][sl->map.player_x] = '0';
	}
}

void	assign_char_left(t_solong *sl)
{
	if (sl->map.player_y == sl->map.exit_y
		&& sl->map.player_x == sl->map.exit_x)
	{
		sl->map.map[sl->map.player_y][sl->map.player_x - 1] = 'P';
		sl->map.map[sl->map.player_y][sl->map.player_x] = 'E';
	}
	else
	{
		sl->map.map[sl->map.player_y][sl->map.player_x - 1] = 'P';
		sl->map.map[sl->map.player_y][sl->map.player_x] = '0';
	}
}

void	assign_char_right(t_solong *sl)
{
	if (sl->map.player_y == sl->map.exit_y
		&& sl->map.player_x == sl->map.exit_x)
	{
		sl->map.map[sl->map.player_y][sl->map.player_x + 1] = 'P';
		sl->map.map[sl->map.player_y][sl->map.player_x] = 'E';
	}
	else
	{
		sl->map.map[sl->map.player_y][sl->map.player_x + 1] = 'P';
		sl->map.map[sl->map.player_y][sl->map.player_x] = '0';
	}
}
