/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:34:21 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* 
*	delta_dist_x :	this serves as the distance the ray has to travel 
*					to go from 1 x-side to the next x-side
*	delta_dist_y :	this serves as the distance the ray has to travel 
*					to go from 1 y-side to the next y-side
*					function fabs() returns the absolute value of 
*					a floating point number
*/
static void	init_ray(t_game *game, int x)
{
	game->raycast.hit = false;
	game->raycast.camera = 2 * (double)x / (double)game->win_w - 1;
	game->raycast.ray_dir_x = game->player.dir_x + \
	game->player.plane_x * game->raycast.camera;
	game->raycast.ray_dir_y = game->player.dir_y + \
	game->player.plane_y * game->raycast.camera;
	game->raycast.map_x = (int)game->player.pos_x;
	game->raycast.map_y = (int)game->player.pos_y;
	game->raycast.number_of_the_wall_hitted = 0;
	game->raycast.delta_dist_x = fabs(1.0 / game->raycast.ray_dir_x);
	game->raycast.delta_dist_y = fabs(1.0 / game->raycast.ray_dir_y);
}

static void	calculate_step_and_initial_side_distance(t_game *game)
{
	if (game->raycast.ray_dir_x < 0)
	{
		game->raycast.step_x = -1;
		game->raycast.side_dist_x = (game->player.pos_x - \
		game->raycast.map_x) * game->raycast.delta_dist_x;
	}
	else
	{
		game->raycast.step_x = 1;
		game->raycast.side_dist_x = (game->raycast.map_x + 1.0 - \
		game->player.pos_x) * game->raycast.delta_dist_x;
	}
	if (game->raycast.ray_dir_y < 0)
	{
		game->raycast.step_y = -1;
		game->raycast.side_dist_y = (game->player.pos_y - \
		game->raycast.map_y) * game->raycast.delta_dist_y;
	}
	else
	{
		game->raycast.step_y = 1;
		game->raycast.side_dist_y = (game->raycast.map_y + 1.0 - \
		game->player.pos_y) * game->raycast.delta_dist_y;
	}
}

static void	dda(t_game *game)
{
	while (!game->raycast.hit)
	{
		if (game->raycast.side_dist_x < game->raycast.side_dist_y)
		{
			game->raycast.side_dist_x += game->raycast.delta_dist_x;
			game->raycast.map_x += game->raycast.step_x;
			game->raycast.side = EW;
			game->raycast.wall_orientation = EAST;
			if (game->raycast.ray_dir_x < 0)
				game->raycast.wall_orientation = WEST;
		}
		else
		{
			game->raycast.side_dist_y += game->raycast.delta_dist_y;
			game->raycast.map_y += game->raycast.step_y;
			game->raycast.side = NS;
			game->raycast.wall_orientation = SOUTH;
			if (game->raycast.ray_dir_y < 0)
				game->raycast.wall_orientation = NORTH;
		}
		if (game->map.map_grid[(int)game->raycast.map_y] \
		[(int)game->raycast.map_x] > 0)
			set_hit_and_wall_number(game);
	}
}

static void	calculate_wall_dist_h_and_text_x(t_game *game)
{
	if (game->raycast.side == EW)
	{
		game->raycast.perp_wall_dist = \
		game->raycast.side_dist_x - game->raycast.delta_dist_x;
		game->raycast.wall_x = game->player.pos_y + \
		game->raycast.perp_wall_dist * game->raycast.ray_dir_y;
	}
	else
	{
		game->raycast.perp_wall_dist = \
		game->raycast.side_dist_y - game->raycast.delta_dist_y;
		game->raycast.wall_x = game->player.pos_x + \
		game->raycast.perp_wall_dist * game->raycast.ray_dir_x;
	}
	game->raycast.wall_height = (double)game->win_h / \
	game->raycast.perp_wall_dist;
	game->raycast.wall_x -= floor(game->raycast.wall_x);
}

/*
*	1. Loop through all the windows from left to right, column by column
*	2. Calculate the ray position and direction
*		2.1 We need to calculate the step and initial side distance
*			meaning we check if player is facing left or right, up or down
*		2.2 We need to calculate the distance to the wall
*			and this for both the x and y side.
*			Because we need to know which side of the wall we hit first
*	3. Perform DDA
*		3.1 We need to check if the ray hit a wall first in the x or y direction
*			3.1.1 check from which side the ray hit the wall (EW or NS)
*			3.1.2 Then determine the orientation of the wall based on dir_x/dir_y
*		3.2 if we hit a wall, we need to set the hit to true 
*			and store the wall number/type
*	4. Calculate the distance to the wall
*		4.1 We need to calculate the distance to the wall
*			 based on the side we hit
*		4.2 With this dist we can calculate the height of the wall strip
*			This is the way to simulate the depth
*		4.3 We need to calculate the texture x coordinate 
*			that we will use to get 
*			the right strip of the texture
*/
int	raycast(t_game *game)
{
	int	current_x;

	mlx_clear_window(game->win.mlx_ptr, game->win.win_ptr);
	current_x = -1;
	while (++current_x < (int)game->win_w)
	{
		init_ray(game, current_x);
		calculate_step_and_initial_side_distance(game);
		dda(game);
		calculate_wall_dist_h_and_text_x(game);
		put_column_to_win(game, current_x);
	}
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
	game->win.scr.mlx_img, 0, 0);
	return (0);
}
