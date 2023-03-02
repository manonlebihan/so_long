/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:47:44 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/02 11:47:48 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WHITE_PIXEL 0xFFFFFF

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1920)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	render(t_solong *sl)
{
	if (sl->mlx.win_ptr == NULL)
		return (1);
	render_background(&sl->img, WHITE_PIXEL);
	mlx_put_image_to_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr,
		sl->img.mlx_img, 0, 0);
	return (0);
}

int	handle_keypress(int keysym, t_solong *sl)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(sl->mlx.mlx_ptr, sl->mlx.win_ptr);
		sl->mlx.win_ptr = NULL;
	}
	return (0);
}

int	display_window(t_solong sl)
{
	sl.mlx.mlx_ptr = mlx_init();
	if (sl.mlx.mlx_ptr == NULL)
		return (1);
	sl.mlx.win_ptr = mlx_new_window(sl.mlx.mlx_ptr, 1920, 1080, "so_long");
	if (sl.mlx.mlx_ptr == NULL)
	{
		free(sl.mlx.mlx_ptr);
		return (1);
	}
	sl.img.mlx_img = mlx_new_image(sl.mlx.mlx_ptr, 1920, 1080);
	sl.img.addr = mlx_get_data_addr(sl.img.mlx_img, &sl.img.bpp,
			&sl.img.line_len, &sl.img.endian);
	mlx_loop_hook(sl.mlx.mlx_ptr, &render, &sl);
	mlx_hook(sl.mlx.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &sl);
	mlx_loop(sl.mlx.mlx_ptr);
	mlx_destroy_image(sl.mlx.mlx_ptr, sl.img.mlx_img);
	mlx_destroy_display(sl.mlx.mlx_ptr);
	free(sl.mlx.mlx_ptr);
	return (0);
}