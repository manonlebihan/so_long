/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:05:59 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/01 16:09:08 by mle-biha         ###   ########.fr       */
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


/* typedef struct s_solong
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	t_img	img;
	//int		cur_img;
}	t_solong; */

typedef struct s_img
{
	void	*mlx_img;
	int		width;
	int		height;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_txt
{
	t_img	floor;
	t_img	wall;
	t_img	player;
	t_img	collect;
	t_img	exit;
}	t_txt;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_txt	txt;
	int		x;
	int		y;
}	t_mlx;

typedef struct s_map
{
	char		**map;
	int			nb_lines;
	int			line_len;
	int			exit;
	int			player;
	int			collectible;
}	t_map;

typedef struct s_solong
{
	t_mlx	mlx;
	t_img	img;
	t_map	map;
}	t_solong;

/******************* MEMORY MAP FUNCTIONS *******************/

void	*ft_realloc_str(void *oldptr, int oldlen, int newlen);
void	load_map(t_map *m, int fd);
void	free_map(t_map m);


/******************* CHECK MAP FUNCTIONS *******************/
// void	check_map(int argc, char *filename);
void	check_extension(char *filename);
int		check_rectangle(t_map m);
int		check_chars(t_map m);
int		check_items(t_map m);
int		check_walls(t_map m);

/******************* DISPLAY FUNCTIONS *******************/
int		display_window(t_solong sl);

#endif