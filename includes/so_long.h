/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:05:59 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/10 15:43:40 by mle-biha         ###   ########.fr       */
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
	int			exit_x;
	int			exit_y;
	int			exit_copy;
	int			player;
	int			enemy;
	int			collectible;
	int			collectible_copy;
	int			player_x;
	int			player_y;
	int			player_x_copy;
	int			player_y_copy;
	int			count;
}	t_map;

typedef struct s_solong
{
	t_mlx	mlx;
	t_img	img;
	t_map	map;
}	t_solong;

/******************* MAP FUNCTIONS *******************/
void	free_map(t_map m);
void	load_map(t_map *m, int fd);
int		duplicate_map(t_map m, t_map *dup);
void	*ft_realloc_str(void *oldptr, int oldlen, int newlen);

/******************* CHECK MAP FUNCTIONS *******************/
int		check_chars(t_map *m);
int		check_items(t_map *m);
int		check_walls(t_map *m);
int		check_rectangle(t_map *m);
int		check_extension(char *filename);

/******************* DISPLAY FUNCTIONS *******************/
void	display_window(t_map map);
int		free_mlx(t_mlx *mlx, t_map *map);

/******************* TETXURES FUNCTIONS *******************/
void	get_textures(t_mlx *mlx);
void	put_textures(t_mlx mlx, t_map map);

/******************* DIRECTION FUNCTIONS *******************/
int		direction(int keycode, t_solong *sl);

#endif