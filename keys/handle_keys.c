/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:07:50 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	rotate(t_game *game, bool rl, double speed)
{
	double	tmp_dir;
	double	tmp_plane;

	if (rl == 1)
		speed *= -1;
	tmp_dir = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(speed) \
	- game->player.dir_y * sin(speed);
	game->player.dir_y = tmp_dir * sin(speed) + \
	game->player.dir_y * cos(speed);
	tmp_plane = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(speed) \
	- game->player.plane_y * sin(speed);
	game->player.plane_y = tmp_plane * sin(speed) + \
	game->player.plane_y * cos(speed);
}

void	handle_keys(t_game *game)
{
	key_esc(game);
	key_enter(game);
	if (game->state == home_screen)
		return ;
	key_tab(game);
	key_space(game);
	key_m(game);
	if (game->state == game_screen)
	{
		key_left(game);
		key_right(game);
		key_w(game);
		key_s(game);
		key_a(game);
		key_d(game);
		key_e(game);
	}
}
