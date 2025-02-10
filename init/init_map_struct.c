/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:02:30 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	init_map_struct(t_game *game)
{
	game->map.map_grid = game->data.map;
	game->map.h = game->data.map_h;
	game->map.w = game->data.map_w;
	game->map.pos_sprite = (t_sprite){0};
	game->map.dynamic_map = false;
	if (game->map.h * FOC_SIZE > MAX_M_H \
		|| game->map.w * FOC_SIZE > MAX_M_W)
		game->map.dynamic_map = true;
	game->map.start_x = 96;
	game->map.start_y = 99;
	if (game->map.dynamic_map == false)
	{
		game->map.start_x = (game->win_w - (game->map.w * FOC_SIZE)) / 2;
		game->map.start_y = (game->win_h - (game->map.h * FOC_SIZE)) / 2;
		game->map.f_startx = MAX_M_W / 2 - (game->map.w * FOC_SIZE) / 2;
		game->map.f_starty = MAX_M_H / 2 - (game->map.h * FOC_SIZE) / 2;
	}
	game->map.f_map_dynamic = new_img(MAX_M_W, MAX_M_H, &game->win);
	game->map.focus_rendered = false;
	return (true);
}
