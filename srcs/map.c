/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:28:03 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/15 22:50:33 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map)
{
	map->map = NULL;
	map->nb_lines = 0;
	map->line_len = 0;
	map->exit = 0;
	map->exit_copy = 0;
	map->exit_x = 0;
	map->exit_y = 0;
	map->player = 0;
	map->enemy = 0;
	map->collectible = 0;
	map->collectible_copy = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->player_x_copy = 0;
	map->player_y_copy = 0;
	map->count = 0;
}

int	duplicate_map(t_map m, t_map *dup)
{
	int	i;

	i = 0;
	dup->nb_lines = m.nb_lines;
	dup->line_len = m.line_len;
	dup->map = (char **)malloc(m.nb_lines * sizeof(char *));
	if (dup->map == NULL)
		return (0);
	while (i < m.nb_lines)
	{
		dup->map[i] = ft_strdup(m.map[i]);
		if (dup->map[i] == NULL)
		{
			while (i)
			{
				free(dup->map[i]);
				i--;
			}
			free(dup->map);
			return (0);
		}
		i++;
	}
	return (1);
}

void	*ft_realloc_str(void *oldptr, int oldlen)
{
	void	*newptr;

	newptr = malloc((oldlen + 1) * sizeof(char *));
	if (oldptr == NULL)
		return (newptr);
	else
	{
		if (newptr != NULL)
			ft_memcpy(newptr, oldptr, oldlen * sizeof(char *));
		free(oldptr);
		return (newptr);
	}
}

int	load_map(t_map *m, int fd)
{
	char	*line;

	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			if (m->nb_lines == 0)
				m->line_len = ft_strlen(line);
			m->map = ft_realloc_str(m->map, m->nb_lines);
			if (m->map != NULL)
			{
				m->map[m->nb_lines] = line;
				m->nb_lines++;
			}
			else
				free(line);
		}
	}
	return (1);
}

void	free_map(t_map m)
{
	int	i;

	i = 0;
	if (m.map != NULL)
	{
		while (i < m.nb_lines)
		{
			if (m.map[i] != NULL)
				free(m.map[i]);
			i++;
		}
		free(m.map);
	}
}
