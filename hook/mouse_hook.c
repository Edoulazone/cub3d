/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:24:38 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	mouse_move(int x, int y, t_game *game)
{
	(void)y;
	if (game->state != game_screen)
		return (0);
	if (x < WIN_W / 2)
		rotate(game, 1, game->player.rot_speed / 3.5);
	else if (x > WIN_W / 2)
		rotate(game, 0, game->player.rot_speed / 3.5);
	return (0);
}

int	mouse_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (game->state == game_screen)
	{
		if (button == Button1)
			game->keys.mouse_1 = true;
		else if (button == Button2)
			game->keys.mouse_2 = true;
		else if (button == Button3)
			game->keys.mouse_3 = true;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (game->state == game_screen)
	{
		if (button == Button1)
			game->keys.mouse_1 = false;
		else if (button == Button2)
			game->keys.mouse_2 = false;
		else if (button == Button3)
			game->keys.mouse_3 = false;
	}
	return (0);
}
