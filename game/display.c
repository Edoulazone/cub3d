/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:33:59 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static t_img	*select_wall_texture(t_game *game)
{
	if (game->raycast.wall_orientation == NORTH)
		return (&game->xpm_images[xpm_north]);
	else if (game->raycast.wall_orientation == SOUTH)
		return (&game->xpm_images[xpm_south]);
	else if (game->raycast.wall_orientation == EAST)
		return (&game->xpm_images[xpm_east]);
	else if (game->raycast.wall_orientation == WEST)
		return (&game->xpm_images[xpm_west]);
	return (&game->xpm_images[xpm_north]);
}

static void	pixel_put_wall(t_game *game, int x, int y, int the_wall)
{
	int		px;
	int		px2;
	int		x2;
	int		y2;
	t_img	*wall;

	(void)the_wall;
	wall = select_wall_texture(game);
	if (game->raycast.wall_orientation == SOUTH \
	|| game->raycast.wall_orientation == WEST)
		x2 = (int)((1 - game->raycast.wall_x) * (double)wall->width);
	else
		x2 = (int)(game->raycast.wall_x * (double)wall->width);
	px = game->win.scr.line_len * y + x * game->win.scr.bpp / 8;
	y = y - (game->win_h / 2 - (int)game->raycast.wall_height / 2);
	y2 = (int)((double)y * (double)wall->height / game->raycast.wall_height);
	px2 = wall->line_len * y2 + x2 * wall->bpp / 8;
	game->win.scr.addr[px + 2] = (char)wall->addr[px2 + 2];
	game->win.scr.addr[px + 1] = (char)wall->addr[px2 + 1];
	game->win.scr.addr[px] = (char)wall->addr[px2];
}

static void	pixel_put_floor(t_game *game, int x, int y)
{
	char	*dst;

	dst = game->win.scr.addr + y * game->win.scr.line_len
		+ x * game->win.scr.bpp / 8;
	*(unsigned int *)dst = game->data.f;
}

static void	pixel_put_sky(t_game *game, int x, int y)
{
	char	*dst;

	dst = game->win.scr.addr + y * game->win.scr.line_len
		+ x * game->win.scr.bpp / 8;
	*(unsigned int *)dst = game->data.c;
}

void	put_column_to_win(t_game *game, int x)
{
	int	y;
	int	draw_end;

	y = 0;
	while (y < -game->raycast.wall_height / 2 + game->win_h / 2)
		pixel_put_sky(game, x, y++);
	y = -(int)game->raycast.wall_height / 2 + game->win_h / 2;
	if (y < 0)
		y = 0;
	draw_end = game->win_h / 2 + (int)game->raycast.wall_height / 2;
	if (draw_end >= (int)game->win_h)
		draw_end = game->win_h;
	while (y < draw_end)
		pixel_put_wall(game, x, y++, game->raycast.number_of_the_wall_hitted);
	while (y < (int)game->win_h)
		pixel_put_floor(game, x, y++);
}
