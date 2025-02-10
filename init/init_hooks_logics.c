/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks_logics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:14:04 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	init_hooks_logics(t_game *game)
{
	mlx_expose_hook(game->win.win_ptr, expose_hook, game);
	mlx_hook(game->win.win_ptr, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win.win_ptr, KeyRelease, KeyReleaseMask, key_release, game);
	mlx_hook(game->win.win_ptr, MotionNotify, PointerMotionMask, \
	mouse_move, game);
	mlx_hook(game->win.win_ptr, ButtonPress, ButtonPressMask, \
	mouse_press, game);
	mlx_hook(game->win.win_ptr, ButtonRelease, ButtonReleaseMask, \
	mouse_release, game);
	mlx_hook(game->win.win_ptr, ClientMessage, StructureNotifyMask, \
	close_game, game);
	mlx_mouse_hide(game->win.mlx_ptr, game->win.win_ptr);
	return (true);
}
