/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:35:32 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/02 14:42:50 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_textures(t_mlx *mlx, t_img *txt, char *path)
{
	txt->mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &txt->height,
			&txt->width);
}

void	get_textures(t_mlx *mlx)
{
	init_textures(mlx, &mlx->txt.floor, "textures/teapot.xpm");
}

void	write_textures(char c, t_mlx mlx, int i, int j)
{
	(void) c;
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.txt.floor.mlx_img,
		(mlx.txt.floor.width * j), (mlx.txt.floor.height * i));
}

void	put_textures(t_mlx mlx, t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.nb_lines)
	{
		j = 0;
		while (j < map.line_len)
		{
			write_textures(map.map[i][j], mlx, i, j);
			j++;
		}
		i++;
	}
}

void	display_window(t_map map)
{
	//t_solong	sl;
	t_mlx		mlx;

	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
	{
		free_map(map);
		exit(EXIT_FAILURE);
	}
	get_textures(&mlx);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr,
			(mlx.txt.floor.width * map.line_len),
			(mlx.txt.floor.height * map.nb_lines), "so_long");
	put_textures(mlx, map);
	mlx_loop(mlx.mlx_ptr);
}
