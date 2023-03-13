/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:35:32 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/13 11:40:14 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_mlx(t_mlx *mlx, t_map *map)
{
	if (mlx->mlx_ptr != NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->txt.collect.mlx_img);
		mlx_destroy_image(mlx->mlx_ptr, mlx->txt.exit.mlx_img);
		mlx_destroy_image(mlx->mlx_ptr, mlx->txt.enemy.mlx_img);
		mlx_destroy_image(mlx->mlx_ptr, mlx->txt.floor.mlx_img);
		mlx_destroy_image(mlx->mlx_ptr, mlx->txt.player.mlx_img);
		mlx_destroy_image(mlx->mlx_ptr, mlx->txt.wall.mlx_img);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	free_map(*map);
	exit(EXIT_SUCCESS);
}

int	destroy_all(t_solong *sl)
{
	free_mlx(&sl->mlx, &sl->map);
	return (0);
}

void	display_window(t_map map)
{
	t_mlx		mlx;
	t_solong	sl;

	sl.map = map;
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
	{
		free_map(map);
		exit(EXIT_FAILURE);
	}
	get_textures(&mlx);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr,
			(mlx.txt.floor.width * (map.line_len - 1)),
			(mlx.txt.floor.height * map.nb_lines), "so_long");
	put_textures(mlx, map);
	sl.mlx = mlx;
	mlx_hook(mlx.win_ptr, 2, 1L << 0, &direction, &sl);
	mlx_hook(mlx.win_ptr, 17, 0L, &destroy_all, &sl);
	mlx_loop(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
}
