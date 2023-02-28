/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:33:14 by mle-biha          #+#    #+#             */
/*   Updated: 2023/02/28 17:11:52 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *filename)
{
	int	i;

	i = 0;
	i = ft_strlen(filename);
	if (filename[i - 1] == 'r' && filename[i - 2] == 'e'
		&& filename[i - 3] == 'b' && filename[i - 4] == '.')
	{
		i = open(filename, O_RDONLY);
		if (i == -1)
		{
			ft_putendl_fd("File does not exist.", 2);
			exit(EXIT_FAILURE);
		}
		else
			close(i);
	}
	else
	{
		ft_putendl_fd("File not valid, should be a .ber file !", 2);
		exit(EXIT_FAILURE);
	}
}

void	check_rectangle(t_memory_map m)
{
	int	len;
	int	nb_lines;

	nb_lines = m.nb_lines;
	while (nb_lines != 1)
	{
		if (nb_lines == m.nb_lines)
			len = (ft_strlen(m.map[m.nb_lines - 1]) + 1);
		else
			len = ft_strlen(m.map[nb_lines - 1]);
		if (m.line_len != len)
			ft_putendl_fd("Not a rectangle...", 2);
		nb_lines--;
	}
}

void	check_chars(t_memory_map m)
{
	int	i;
	int	j;

	j = 0;
	while (m.map[j] != NULL)
	{
		i = 0;
		while (m.map[j][i] != '\0')
		{
			if (m.map[j][i] != '1' && m.map[j][i] != '0' &&
					m.map[j][i] != 'E' && m.map[j][i] != 'C'
					&& m.map[j][i] != 'P' && m.map[j][i] != '\n')
			{
				ft_putendl_fd("Map not well formated !", 2);
				return ;
			}
			i++;
		}
		j++;
	}
}

void	check_walls(t_memory_map m)
{
	int	i;
	int	j;

	j = 0;
	while (m.map[j] != NULL)
	{
		i = 0;
		while (m.map[0][i] == '1' && m.map[m.nb_lines - 1][i] == '1')
			i++;
		if (i != (m.line_len - 1))
		{
			ft_putendl_fd("Map not surronded by walls...", 2);
			return ;
		}
		i = 1;
		while (i != (m.nb_lines - 1))
		{
			if (m.map[i][0] != '1' || m.map[i][m.line_len - 2] != '1')
			{
				ft_putendl_fd("Map not surronded by walls...", 2);
				return ;
			}
			i++;
		}
		j++;
	}
}

void	check_map(int argc,	char *filename)
{
	t_memory_map	map;
	int				fd;

	if (argc != 2)
	{
		ft_putendl_fd("Not enough arguments, usage: ./so_long [file.ber]", 2);
		exit(EXIT_FAILURE);
	}
	check_extension(filename);
	fd = open(filename, O_RDONLY);
	load_memory_map(&map, fd);
	close(fd);
	check_rectangle(map);
	check_chars(map);
	check_walls(map);
	free_memory_map(map);
}
