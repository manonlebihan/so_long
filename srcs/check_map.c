/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:33:14 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/06 23:10:26 by mle-biha         ###   ########.fr       */
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

int	check_rectangle(t_map *m)
{
	int	len;
	int	nb_lines;

	nb_lines = m->nb_lines;
	while (nb_lines != 1)
	{
		if (nb_lines == m->nb_lines)
			len = (ft_strlen(m->map[m->nb_lines - 1]) + 1);
		else
			len = ft_strlen(m->map[nb_lines - 1]);
		if (m->line_len != len)
			return (0);
		nb_lines--;
	}
	return (1);
}

int	check_chars(t_map *m)
{
	int	i;
	int	j;

	j = 0;
	while (j != m->nb_lines)
	{
		i = 0;
		while (m->map[j][i] != '\0')
		{
			if (m->map[j][i] != '1' && m->map[j][i] != '0' &&
					m->map[j][i] != 'E' && m->map[j][i] != 'C'
					&& m->map[j][i] != 'P' && m->map[j][i] != '\n')
			{
				return (0);
			}
			if (m->map[j][i] == 'P')
			{
				m->player_x = i;
				m->player_y = j;
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	check_items(t_map *m)
{
	int	i;
	int	j;

	j = 0;
	m->exit = 0;
	m->player = 0;
	m->collectible = 0;
	while (j != m->nb_lines)
	{
		i = 0;
		while (m->map[j][i] != '\0')
		{
			if (m->map[j][i] == 'E')
				m->exit++;
			else if (m->map[j][i] == 'P')
				m->player++;
			else if (m->map[j][i] == 'C')
				m->collectible++;
			i++;
		}
		j++;
	}
	if (m->exit != 1 || m->player != 1 || m->collectible != 1)
		return (0);
	return (1);
}

int	check_walls(t_map *m)
{
	int	i;
	int	j;

	j = 0;
	while (j != m->nb_lines)
	{
		i = 0;
		while (m->map[0][i] == '1' && m->map[m->nb_lines - 1][i] == '1')
			i++;
		if (i != (m->line_len - 1))
			return (0);
		i = 1;
		while (i != (m->nb_lines - 1))
		{
			if (m->map[i][0] != '1' || m->map[i][m->line_len - 2] != '1')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
