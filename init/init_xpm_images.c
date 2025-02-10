/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:26:32 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	init_xpm_images(t_game *game)
{
	t_img	*xpm;

	xpm = game->xpm_images;
	xpm[xpm_home_screen] = set_new_xpm("assets/home_screen.xpm", &game->win);
	xpm[xpm_game_over] = set_new_xpm("assets/game_over.xpm", &game->win);
	xpm[xpm_menu] = set_new_xpm("assets/menu.xpm", &game->win);
	xpm[xpm_map_focus] = set_new_xpm("assets/map.xpm", &game->win);
	xpm[xpm_inventory] = set_new_xpm("assets/inventory.xpm", &game->win);
	xpm[xpm_north] = set_new_xpm(game->data.no, &game->win);
	xpm[xpm_south] = set_new_xpm(game->data.so, &game->win);
	xpm[xpm_east] = set_new_xpm(game->data.ea, &game->win);
	xpm[xpm_west] = set_new_xpm(game->data.we, &game->win);
	xpm[xpm_wall] = set_new_xpm("assets/wall_blank.xpm", &game->win);
	xpm[xpm_door] = set_new_xpm("assets/door.xpm", &game->win);
	xpm[xpm_grid] = set_new_xpm("assets/grid.xpm", &game->win);
	xpm[xpm_scaffold] = set_new_xpm("assets/scaffold.xpm", &game->win);
	xpm[xpm_pipe] = set_new_xpm("assets/pipe.xpm", &game->win);
	xpm[xpm_metal] = set_new_xpm("assets/metal.xpm", &game->win);
	xpm[xpm_metal2] = set_new_xpm("assets/metal2.xpm", &game->win);
	return (true);
}
