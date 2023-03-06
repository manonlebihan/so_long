/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:23:09 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/06 16:28:06 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (0);
}

int	check_map(int argc,	char *filename, t_map *map)
{
	int		fd;

	if (argc != 2)
	{
		ft_putendl_fd("Not enough arguments, usage: ./so_long [file.ber]", 2);
		exit(EXIT_FAILURE);
	}
	check_extension(filename);
	fd = open(filename, O_RDONLY);
	load_map(map, fd);
	close(fd);
	if (check_rectangle(*map) == (0))
		return (ft_error("Map is not a rectangle."));
	if (check_chars(map) == 0)
		return (ft_error("Map contains forbidden characters."));
	if (check_items(*map) == 0)
		return (ft_error("There is either too many items or not enough."));
	if (check_walls(*map) == 0)
		return (ft_error("Map is not surronded by walls."));
	return (1);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (check_map(argc, argv[1], &map) == 1)
	{
		printf("C'est OK\n");
		display_window(map);
	}
	free_map(map);
	return (1);
}
