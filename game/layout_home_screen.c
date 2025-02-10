/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_home_screen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:31:55 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	layout_home_screen(t_game *game)
{
	put_img_to_img(&game->win.scr, &game->xpm_images[xpm_home_screen], 0, 0);
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
	game->win.scr.mlx_img, 0, 0);
	return (0);
}
