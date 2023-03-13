/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:54:52 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/13 10:55:00 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
