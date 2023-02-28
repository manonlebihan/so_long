/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:23:09 by mle-biha          #+#    #+#             */
/*   Updated: 2023/02/28 11:23:04 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_realloc_str(void *oldptr, int oldlen, int newlen)
{
	void	*newptr;

	if (newlen == 0)
	{
		free(oldptr);
		return (NULL);
	}
	else if (oldptr == NULL)
		return (malloc(newlen * sizeof(char *)));
	else if (newlen <= oldlen)
		return (oldptr);
	else
	{
		newptr = malloc(newlen * sizeof(char *));
		if (newptr)
		{
			ft_memcpy(newptr, oldptr, oldlen * sizeof(char *));
			free(oldptr);
		}
		return (newptr);
	}
}

void	load_memory_map(t_memory_map *map, int fd)
{
	char	*line;
	
	map->map = NULL;
	map->nb_lines = 0;
	line = "";

	while(line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			if (map->nb_lines == 0)
				map->line_len = ft_strlen(line);
			map->map = ft_realloc_str(map->map, map->nb_lines, map->nb_lines + 1);
			map->map[map->nb_lines] = line;
			map->nb_lines++;
		}
	}
}

void	free_memory_map(t_memory_map map)
{
	int	i;
	
	i = 0;
	while(i < map.nb_lines)
	{
		free(map.map[i]);
		i++;
	}
	free(map.map);
}

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
