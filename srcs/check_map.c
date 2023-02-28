/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:33:14 by mle-biha          #+#    #+#             */
/*   Updated: 2023/02/28 15:16:40 by mle-biha         ###   ########.fr       */
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

/* void	check_if_map_is_closed(t_memory_map m)
{
	
} */

void	check_chars(t_memory_map m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m.map[j] != NULL)
	{
		printf("m.map[j] : %s\n", m.map[j]);
		while (m.map[j][i] != '\0')
		{
			printf("map[j][i] : %c\n", m.map[j][i]);
			if (m.map[j][i] != '1' && m.map[j][i] != '\n')
				ft_putendl_fd("Map not well formated !", 2);
			else
				ft_putendl_fd("ALL GOOD", 1);
			i++;
		}
		j++;
	}
}



/* if (m.map[j][i] != '1' && m.map[j][i] != '0' && 
					m.map[j][i] != 'E' && m.map[j][i] != 'C' 
					&& m.map[j][i] != 'P' && m.map[j][i] != '\n') */

/* int	check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		printf("str[i] : %c", str[i]);
		if (str[i] != 'a')
			return (1);
		i++;
	}
	return (0);
} */

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
	free_memory_map(map);
}

	/* int				i;
	i = 0;
	printf("nb line   = %d\n", map.nb_lines);
	printf("line size = %d\n", map.line_len);
	while (i < map.nb_lines)
	{
		printf("%s", map.map[i]);
		i++;
	} */
