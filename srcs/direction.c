/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:55:44 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/06 17:51:10 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up()
{
	
}

void	move_down()
{
	
}

void	move_left()
{
	
}

void	move_right()
{
	
}

int	direction(int keycode, t_solong *sl)
{
	if (keycode == 65307)
		free_mlx(&sl->mlx, &sl->map);
	return (0);
}