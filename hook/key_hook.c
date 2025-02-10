/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:25:29 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->keys.w = true;
	else if (keycode == XK_s)
		game->keys.s = true;
	else if (keycode == XK_a)
		game->keys.a = true;
	else if (keycode == XK_d)
		game->keys.d = true;
	else if (keycode == XK_Left)
		game->keys.left = true;
	else if (keycode == XK_Right)
		game->keys.right = true;
	else if (keycode == XK_e)
		game->keys.e = true;
	else if (keycode == XK_Return)
		game->keys.enter = true;
	else if (keycode == XK_space)
		game->keys.space = true;
	else if (keycode == XK_Tab)
		game->keys.tab = true;
	else if (keycode == XK_m)
		game->keys.m = true;
	else if (keycode == XK_Escape)
		game->keys.esc = true;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->keys.w = false;
	else if (keycode == XK_s)
		game->keys.s = false;
	else if (keycode == XK_a)
		game->keys.a = false;
	else if (keycode == XK_d)
		game->keys.d = false;
	else if (keycode == XK_Left)
		game->keys.left = false;
	else if (keycode == XK_Right)
		game->keys.right = false;
	else if (keycode == XK_e)
		game->keys.e = false;
	else if (keycode == XK_Return)
		game->keys.enter = false;
	else if (keycode == XK_space)
		game->keys.space = false;
	else if (keycode == XK_Tab)
		game->keys.tab = false;
	else if (keycode == XK_m)
		game->keys.m = false;
	else if (keycode == XK_Escape)
		game->keys.esc = false;
	return (0);
}
