/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:47:44 by mle-biha          #+#    #+#             */
/*   Updated: 2023/03/09 13:59:30 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// INIT
void	init_map(t_map *map)
{
	map->map = NULL;
	map->nb_lines = 0;
	map->line_len = 0;
	map->exit = 0;
	map->player = 0;
	map->collectible = 0;
}
