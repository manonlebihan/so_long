/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:23:09 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/15 19:18:18 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	return (0);
}

int	first_check(int argc, char *filename, t_map *map)
{
	int		fd;

	if (argc != 2)
	{
		ft_putendl_fd("Error\nNumber of arguments invalid, should be one.", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error("File does not exist."));
	if (check_extension(filename) == 0)
		return (ft_error("File not valid, should be a .ber file."));
	if (load_map(map, fd) == 0)
	{
		close(fd);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Something went wrong...", 2);
		return (0);
	}
	close(fd);
	if (map->map == NULL)
		return (0);
	return (1);
}

int	check_map(int argc,	char *filename, t_map *map)
{
	if (first_check(argc, filename, map) == 0)
		return (0);
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
