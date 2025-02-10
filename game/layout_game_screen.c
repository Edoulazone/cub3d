/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_game_screen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:09:25 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	layout_game_screen(t_game *game)
{
	if (game->state == game_screen)
	{
		raycast(game);
		minimap(game);
		player_hand(game);
		mlx_mouse_move(game->win.mlx_ptr, game->win.win_ptr, \
			WIN_W / 2, WIN_H / 2);
	}
	else if (game->state == inventory)
		put_img_to_img(&game->win.scr, &game->xpm_images[xpm_inventory], 0, 0);
	else if (game->state == map_focus)
		layout_map_screen(game);
	else if (game->state == menu)
		put_img_to_img(&game->win.scr, &game->xpm_images[xpm_menu], 0, 0);
	else if (game->state == game_over)
		put_img_to_img(&game->win.scr, &game->xpm_images[xpm_game_over], 0, 0);
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
	game->win.scr.mlx_img, 0, 0);
	return (0);
}
