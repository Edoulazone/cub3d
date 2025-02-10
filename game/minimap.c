/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:52:59 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*	Cycle through the markers to find the one that is the closest 
*	to the current angle of the player. Modify "current_node"
*	1. Calculate the angle of the player
*	2. Round the angle to the nearest 15 degrees to find
*	3. With this info, cycle through the markers to find 
*		the exact min angle one
*/
static void	find_current_marker(t_sprite *player_sprite, t_player player)
{
	float	angle;
	float	angle_degrees;
	float	to_find;

	angle = atan2(player.dir_y, player.dir_x);
	angle_degrees = angle * (180.0 / M_PI);
	if (angle_degrees < 0)
		angle_degrees += 360;
	to_find = (floor(angle_degrees / 15) * 15) + 7.500f;
	while (((t_marker *)player_sprite->cur_node->content)->min_angle != to_find)
		player_sprite->cur_node = player_sprite->cur_node->next;
}

static void	calculate_start_pos(t_game *game, float *start_x, float *start_y)
{
	*start_x = game->player.pos_x * MINI_SIZE - (float)MINI_W / 2;
	*start_y = game->player.pos_y * MINI_SIZE - (float)MINI_H / 2;
}

static void	draw_minimap_cell(t_game *game, t_cell_param p)
{
	if ((p.start_y + p.i >= 0 && p.start_y + p.i <= MINI_SIZE * MINI_H) && \
		(p.start_x + p.j >= 0 && p.start_x + p.j <= MINI_SIZE * MINI_W) && \
		(p.y >= 0 && p.y < game->map.h) && \
		(p.x >= 0 && p.x < game->map.w))
	{
		if (is_wall(game->map.map_grid[p.y][p.x]))
			img_pix_put(&game->win.scr, p.j + \
			PADDING, p.i + PADDING, C_DARK_GREY);
		else if (game->map.map_grid[p.y][p.x] == ID_DOOR)
			img_pix_put(&game->win.scr, p.j + \
			PADDING, p.i + PADDING, C_DEEP_RED);
		else if (game->map.map_grid[p.y][p.x] == ID_HIDDEN)
			img_pix_put(&game->win.scr, p.j + \
			PADDING, p.i + PADDING, C_BLACK);
		else if (game->map.map_grid[p.y][p.x] == ID_FLOOR)
			img_pix_put(&game->win.scr, p.j + \
			PADDING, p.i + PADDING, C_GREY);
		else
			img_pix_put(&game->win.scr, p.j + \
			PADDING, p.i + PADDING, C_BLACK);
	}
	else
		img_pix_put(&game->win.scr, p.j + PADDING, p.i + PADDING, C_BLACK);
}

static void	draw_minimap_grid(t_game *game, float start_x, float start_y)
{
	t_cell_param	param;

	param.i = -1;
	while (++param.i < MINI_H)
	{
		param.j = -1;
		while (++param.j < MINI_W)
		{
			param.x = (int)(start_x + param.j) / MINI_SIZE;
			param.y = (int)(start_y + param.i) / MINI_SIZE;
			param.start_x = start_x;
			param.start_y = start_y;
			draw_minimap_cell(game, param);
		}
	}
}

void	minimap(t_game *game)
{
	float	start_x;
	float	start_y;
	t_img	*frame;

	calculate_start_pos(game, &start_x, &start_y);
	draw_minimap_grid(game, start_x, start_y);
	find_current_marker(&game->map.pos_sprite, game->player);
	frame = &((t_marker *)game->map.pos_sprite.cur_node->content)->frame;
	put_img_to_img(&game->win.scr, frame, MINI_W / 2 + PADDING - \
	frame->width / 2, MINI_H / 2 + PADDING - frame->height / 2);
}
