/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:23:09 by mle-biha          #+#    #+#             */
/*   Updated: 2023/02/28 11:32:16 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_memory_map	map;
	int				fd;
	int				i;

	if (argc != 2)
	{
		ft_putendl_fd("usage: ./so_long [file.ber]", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	load_memory_map(&map, fd);
	close(fd);
	printf("nb line   = %d\n", map.nb_lines);
	printf("line size = %d\n", map.line_len);
	i = 0;
	while (i < map.nb_lines)
	{
		printf("%s", map.map[i]);
		i++;
	}
	free_memory_map(map);
}
