/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:47:44 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/08 19:12:36 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// INIT
void	init_map(t_map *map)
{
	map->map = NULL;
	map->nb_lines = 0;
	map->line_len = 0;
	map->exit = 0;
	map->player = 0;
	map->collectible = 0;
}


int	main(int argc, char *argv[])
{
	t_map	map;
	//int		i;
	t_map	dup;

	if (check_map(argc, argv[1], &map) == 1)
	{
		printf("C'est OK\n");
		/* printf("nb_lignes    = %d \n", map.nb_lines);
		printf("taille ligne = %d \n", map.line_len);
		i = 0;
		printf("MAP\n");
		while (i < map.nb_lines) 
		{
			printf("%s\n", map.map[i]);
			i++;
		}
		printf("\n"); */
		if (duplicate_map(map, &dup))
		{
			/* i = 0;
			printf("DUP\n");
			while (i < dup.nb_lines) 
			{
				printf("%s\n", dup.map[i]);
				i++;
			} */
			dup.flood_fill_collectible = 0;
			dup.flood_file_exit = 0;
			/* dup.player_x_copy = map.player_x;
			dup.player_y_copy = map.player_y; */
			/* printf("map Player x %d\n", map.player_x);
			printf("dup Player x %d\n", dup.player_x_copy);
			printf("map Player y %d\n", map.player_y);
			printf("dup Player y %d\n", dup.player_y_copy); */
// pb here
			flood_fill(&dup, dup.player_x, dup.player_y);
// all good from here
			if (dup.flood_fill_collectible == 1 && dup.flood_file_exit == 1)
			{
				printf("C'est OK!\n");
			}
			else
				printf("There is no possible path...\nm");
			free_map(dup);
		}
		map.count = 0;
		display_window(map);
	}
	free_map(map);
	return (1);
}