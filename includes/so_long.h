/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:05:59 by mle-biha          #+#    #+#             */
/*   Updated: 2023/02/28 11:30:18 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include <string.h>

# include <X11/X.h>
# include <X11/keysym.h>

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"

/******************* STRUCTS *******************/

typedef struct	s_img
{
	void	*mlx_img;
	int		width;
	int		height;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct	s_solong
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	t_img	img;
	//int		cur_img;
}	t_solong;

typedef struct	s_memory_map
{
	char	**map;
	int		nb_lines;
	int		line_len;
}	t_memory_map;

/******************* MEMORY MAP FUNCTIONS *******************/

void	*ft_realloc_str(void *oldptr, int oldlen, int newlen);
void	load_memory_map(t_memory_map *map, int fd);
void	free_memory_map(t_memory_map map);

# endif