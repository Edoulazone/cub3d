/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_map_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:46:59 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	print_loop_dynamic_map(t_game *game, int start_pos_x, \
	int start_pos_y)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	while (++y < game->map.h)
	{
		x = -1;
		while (++x < game->map.w)
		{
			if (is_wall(game->map.map_grid[y][x]))
				color = C_DARK_GREY;
			else if (game->map.map_grid[y][x] == 0)
				color = C_GREY;
			else if (game->map.map_grid[y][x] == ID_DOOR)
				color = C_DEEP_RED;
			else if (game->map.map_grid[y][x] == ID_HIDDEN)
				color = C_BLACK;
			else
				color = C_BLACK;
			draw_rect((t_rect){&game->map.f_map_dynamic, start_pos_x + (x * \
			FOC_SIZE), start_pos_y + \
			(y * FOC_SIZE), FOC_SIZE, FOC_SIZE, color});
		}
	}
}

static void	fixed_focus_map(t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	while (++y < game->map.h)
	{
		x = -1;
		while (++x < game->map.w)
		{
			if (is_wall(game->map.map_grid[y][x]))
				color = C_DARK_GREY;
			else if (game->map.map_grid[y][x] == 0)
				color = C_GREY;
			else if (game->map.map_grid[y][x] == ID_DOOR)
				color = C_DEEP_RED;
			else if (game->map.map_grid[y][x] == ID_HIDDEN)
				color = C_BLACK;
			else
				color = C_BLACK;
			draw_rect((t_rect){&game->map.f_map_dynamic, \
			game->map.f_startx + (x * FOC_SIZE), \
			game->map.f_starty + (y * FOC_SIZE), FOC_SIZE, FOC_SIZE, color});
		}
	}
}

static void	dynamic_focus_map(t_game *game)
{
	int	tile_pos_x;
	int	tile_pos_y;
	int	start_pos_x;
	int	start_pos_y;

	tile_pos_x = (int)game->player.pos_x;
	tile_pos_y = (int)game->player.pos_y;
	start_pos_x = MAX_M_W / 2 - \
	(tile_pos_x * FOC_SIZE);
	start_pos_y = MAX_M_H / 2 - \
	(tile_pos_y * FOC_SIZE);
	print_loop_dynamic_map(game, start_pos_x, start_pos_y);
}

/*
* info:	max size of the map is 1008x402 (MAX_M_W x MAX_M_H)
* 		position of the map top left corner is x: 96, y: 99
*/
void	layout_map_screen(t_game *game)
{
	t_marker	*current;
	t_img		*img;
	t_map		m;

	m = game->map;
	current = (t_marker *)m.pos_sprite.cur_node->content;
	img = &current->frame;
	if (!m.focus_rendered)
	{
		draw_rect((t_rect){&m.f_map_dynamic, 0, 0, MAX_M_W, MAX_M_H, C_BLACK});
		if (m.dynamic_map)
			dynamic_focus_map(game);
		else
			fixed_focus_map(game);
		m.focus_rendered = true;
	}
	put_img_to_img(&game->win.scr, &game->xpm_images[xpm_map_focus], 0, 0);
	put_img_to_img(&game->win.scr, &m.f_map_dynamic, 96, 99);
	if (m.dynamic_map)
		put_img_to_img(&game->win.scr, img, WIN_W / 2 - \
		img->width / 2, WIN_H / 2 - img->height / 2);
	else
		put_img_to_img(&game->win.scr, img, m.start_x + \
		(game->player.pos_x * FOC_SIZE) - img->width / 2, m.start_y \
		+ (game->player.pos_y * FOC_SIZE) - img->height / 2);
}
