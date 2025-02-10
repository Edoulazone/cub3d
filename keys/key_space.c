/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:21:46 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	key_space(t_game *game)
{
	if (game->keys.space && !game->keys.space_pressed)
	{
		game->keys.space_pressed = true;
		if (game->state == game_screen)
			game->state = map_focus;
		else if (game->state == map_focus)
		{
			game->map.focus_rendered = false;
			game->state = game_screen;
		}
	}
	else if (!game->keys.space)
		game->keys.space_pressed = false;
}
