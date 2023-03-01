/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:23:09 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/01 11:04:35 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(int argc,	char *filename)
{
	t_map	map;
	int		fd;

	if (argc != 2)
	{
		ft_putendl_fd("Not enough arguments, usage: ./so_long [file.ber]", 2);
		exit(EXIT_FAILURE);
	}
	check_extension(filename);
	fd = open(filename, O_RDONLY);
	load_map(&map, fd);
	close(fd);
	if (check_rectangle(map) == (0))
		ft_putendl_fd("Map is not a rectangle.", 2);
	if (check_chars(map) == 0)
		ft_putendl_fd("Map contains forbidden characters.", 2);
	if (check_items(map) == 0)
		ft_putendl_fd("There is either too many items or not enough.", 2);
	if (check_walls(map) == 0)
		ft_putendl_fd("Map is not surronded by walls.", 2);
	free_map(map);
}

int	main(int argc, char *argv[])
{
	check_map(argc, argv[1]);
}
