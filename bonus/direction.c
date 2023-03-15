/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:55:44 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/13 10:52:32 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_solong *sl)
{
	if (sl->map.map[sl->map.player_y - 1][sl->map.player_x] != '1')
	{
		sl->map.count++;
		if (sl->map.map[sl->map.player_y - 1][sl->map.player_x] == 'C')
			sl->map.collectible--;
		else if (sl->map.map[sl->map.player_y - 1][sl->map.player_x] == 'B')
		{
			ft_printf("Ooooh you died :( Try again !\n");
			free_mlx(&(sl->mlx), &(sl->map));
		}
		else if (sl->map.map[sl->map.player_y - 1][sl->map.player_x] == 'E' &&
			sl->map.collectible == 0)
		{
			ft_printf("You won with %d moves !\n", sl->map.count);
			free_mlx(&(sl->mlx), &(sl->map));
		}
		assign_char_up(sl);
		sl->map.player_y--;
		ft_printf("Number of moves : %d\n", sl->map.count);
	}
	put_textures(sl->mlx, sl->map);
}

void	move_down(t_solong *sl)
{
	if (sl->map.map[sl->map.player_y + 1][sl->map.player_x] != '1')
	{
		sl->map.count++;
		if (sl->map.map[sl->map.player_y + 1][sl->map.player_x] == 'C')
			sl->map.collectible--;
		else if (sl->map.map[sl->map.player_y + 1][sl->map.player_x] == 'B')
		{
			ft_printf("Ooooh you died :( Try again !\n");
			free_mlx(&(sl->mlx), &(sl->map));
		}
		else if (sl->map.map[sl->map.player_y + 1][sl->map.player_x] == 'E' &&
			sl->map.collectible == 0)
		{
			ft_printf("You won with %d moves !\n", sl->map.count);
			free_mlx(&(sl->mlx), &(sl->map));
		}
		assign_char_down(sl);
		sl->map.player_y++;
		ft_printf("Number of moves : %d\n", sl->map.count);
	}
	put_textures(sl->mlx, sl->map);
}

void	move_left(t_solong *sl)
{
	if (sl->map.map[sl->map.player_y][sl->map.player_x - 1] != '1')
	{
		sl->map.count++;
		if (sl->map.map[sl->map.player_y][sl->map.player_x - 1] == 'C')
			sl->map.collectible--;
		else if (sl->map.map[sl->map.player_y][sl->map.player_x - 1] == 'B')
		{
			ft_printf("Ooooh you died :( Try again !\n");
			free_mlx(&(sl->mlx), &(sl->map));
		}
		else if (sl->map.map[sl->map.player_y][sl->map.player_x - 1] == 'E' &&
			sl->map.collectible == 0)
		{
			ft_printf("You won with %d moves !\n", sl->map.count);
			free_mlx(&(sl->mlx), &(sl->map));
		}
		assign_char_left(sl);
		sl->map.player_x--;
		ft_printf("Number of moves : %d\n", sl->map.count);
	}
	put_textures(sl->mlx, sl->map);
}

void	move_right(t_solong *sl)
{
	if (sl->map.map[sl->map.player_y][sl->map.player_x + 1] != '1')
	{
		sl->map.count++;
		if (sl->map.map[sl->map.player_y][sl->map.player_x + 1] == 'C')
			sl->map.collectible--;
		else if (sl->map.map[sl->map.player_y][sl->map.player_x + 1] == 'B')
		{
			ft_printf("Ooooh you died :( Try again !\n");
			free_mlx(&(sl->mlx), &(sl->map));
		}
		else if (sl->map.map[sl->map.player_y][sl->map.player_x + 1] == 'E' &&
			sl->map.collectible == 0)
		{
			ft_printf("You won with %d moves !\n", sl->map.count);
			free_mlx(&(sl->mlx), &(sl->map));
		}
		assign_char_right(sl);
		sl->map.player_x++;
		ft_printf("Number of moves : %d\n", sl->map.count);
	}
	put_textures(sl->mlx, sl->map);
}

int	direction(int keycode, t_solong *sl)
{
	if (keycode == 65307)
		free_mlx(&sl->mlx, &sl->map);
	else if (keycode == 119)
		move_up(sl);
	else if (keycode == 115)
		move_down(sl);
	else if (keycode == 100)
		move_right(sl);
	else if (keycode == 97)
		move_left(sl);
	return (0);
}
