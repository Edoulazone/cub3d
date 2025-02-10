/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:15:22 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	init_keys_struct(t_game *game)
{
	game->keys.w = false;
	game->keys.a = false;
	game->keys.s = false;
	game->keys.d = false;
	game->keys.e = false;
	game->keys.left = false;
	game->keys.right = false;
	game->keys.esc = false;
	game->keys.enter = false;
	game->keys.space = false;
	game->keys.tab = false;
	game->keys.m = false;
	game->keys.m_pressed = false;
	game->keys.tab_pressed = false;
	game->keys.enter_pressed = false;
	game->keys.space_pressed = false;
	game->keys.mouse_left = false;
	game->keys.mouse_right = false;
	game->keys.mouse_1 = false;
	game->keys.mouse_2 = false;
	game->keys.mouse_3 = false;
	return (true);
}
