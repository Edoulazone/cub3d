/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_m.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:23:29 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	key_m(t_game *game)
{
	if (game->keys.m && !game->keys.m_pressed)
	{
		game->keys.m_pressed = true;
		if (game->state == game_screen)
			game->state = menu;
		else if (game->state == menu)
			game->state = game_screen;
	}
	else if (!game->keys.m)
		game->keys.m_pressed = false;
}
