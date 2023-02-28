/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:28:03 by mle-biha          #+#    #+#             */
/*   Updated: 2023/02/28 13:17:23 by mle-biha         ###   ########.fr       */
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

void	load_memory_map(t_memory_map *m, int fd)
{
	char	*line;

	m->map = NULL;
	m->nb_lines = 0;
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			if (m->nb_lines == 0)
				m->line_len = ft_strlen(line);
			m->map = ft_realloc_str(m->map, m->nb_lines, m->nb_lines + 1);
			m->map[m->nb_lines] = line;
			m->nb_lines++;
		}
	}
}

void	free_memory_map(t_memory_map m)
{
	int	i;

	i = 0;
	while (i < m.nb_lines)
	{
		free(m.map[i]);
		i++;
	}
	free(m.map);
}