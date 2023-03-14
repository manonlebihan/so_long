/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:23:09 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/14 14:22:05 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	return (0);
}

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

int	check_map(int argc,	char *filename, t_map *map)
{
	int		fd;

	if (argc != 2)
	{
		ft_putendl_fd("Error\nNot enough arguments : ./so_long [file.ber]", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error("File does not exist."));
	if (check_extension(filename) == 0)
		return (ft_error("File not valid, should be a .ber file."));
	load_map(map, fd);
	close(fd);
	if (check_rectangle(map) == (0))
		return (ft_error("Map is not a rectangle."));
	if (check_chars(map) == 0)
		return (ft_error("Map contains forbidden characters."));
	if (check_items(map) == 0)
		return (ft_error("There is either too many items or not enough."));
	if (check_walls(map) == 0)
		return (ft_error("Map is not surronded by walls."));
	if (check_flood_fill(*map) == 0)
		return (ft_error("There is no possible path..."));
	return (1);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	init_map(&map);
	if (check_map(argc, argv[1], &map) == 1)
		display_window(map);
	free_map(map);
	return (1);
}
