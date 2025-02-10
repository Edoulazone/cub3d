/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:12:57 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	init_window_struct(t_game **game)
{
	(*game)->win.mlx_ptr = mlx_init();
	if (!(*game)->win.mlx_ptr)
		return (printf("Error: mlx_init\n"), false);
	(*game)->win.win_ptr = mlx_new_window((*game)->win.mlx_ptr, \
	(*game)->win_w, (*game)->win_h, TITLE);
	if (!(*game)->win.win_ptr)
		return (printf("Error: mlx_new_window\n"), false);
	(*game)->win.title = TITLE;
	(*game)->win.width = WIN_W;
	(*game)->win.height = WIN_H;
	(*game)->win.scr = new_img((*game)->win.width, \
	(*game)->win.height, &(*game)->win);
	return (true);
}
