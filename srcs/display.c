/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:35:32 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/03 16:03:27 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* int	handle_keypress(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->txt.floor.mlx_img);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->win_ptr = NULL;
	}
	return (0);
} */
int	free_mlx(t_mlx *mlx, t_map *map)
{
	if (mlx->mlx_ptr != NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->txt.floor.mlx_img);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		free(mlx->mlx_ptr);
	}
	free_map(*map);
	exit(EXIT_SUCCESS);
}

int	direction(int keycode, t_solong *sl)
{
	if (keycode == 65307)
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
			(mlx.txt.floor.width * map.line_len),
			(mlx.txt.floor.height * map.nb_lines), "so_long");
	put_textures(mlx, map);
	sl.mlx = mlx;
	//mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &mlx);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, direction, &sl);
	mlx_loop(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
}
