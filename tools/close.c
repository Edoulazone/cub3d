/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:56:07 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* IN GENERAL:
** Destroy image and xpm images
** Destroy display
** Destroy window
** Destroy map grid
** Free mlx_ptr
** Free main game struct
*/
static void	destroy_animation_struct(t_game *game, \
	t_animation *anim)
{
	t_list	*current;
	t_list	*next;
	t_img	*img;
	int		i;

	next = NULL;
	current = anim->sequence;
	mlx_destroy_image(game->win.mlx_ptr, \
	anim->sprite_img.mlx_img);
	i = -1;
	while (++i < anim->total_frame)
	{
		img = (t_img *)current->content;
		mlx_destroy_image(game->win.mlx_ptr, img->mlx_img);
		next = current->next;
		free(img);
		free(current);
		if (next == anim->sequence)
			break ;
		current = next;
	}
	anim->sequence = NULL;
}

static void	destroy_map_struct(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.h)
		free(game->map.map_grid[i++]);
	free(game->map.map_grid);
	mlx_destroy_image(game->win.mlx_ptr, \
	game->map.f_map_dynamic.mlx_img);
}

static void	destroy_marker_struct(t_game *game)
{
	t_lst	*current;
	t_lst	*next;

	next = NULL;
	current = game->map.pos_sprite.anim;
	while (current)
	{
		next = current->next;
		mlx_destroy_image(game->win.mlx_ptr, \
		((t_marker *)current->content)->frame.mlx_img);
		free((t_marker *)current->content);
		free(current);
		if (next == game->map.pos_sprite.anim)
			break ;
		current = next;
	}
	game->map.pos_sprite.anim = NULL;
	free(game->map.pos_sprite.file_path);
	free(game->map.pos_sprite.name);
	mlx_destroy_image(game->win.mlx_ptr, \
	game->map.pos_sprite.sprite_img.mlx_img);
}

static void	destroy_xpms(t_win win, t_img *xpm_images)
{
	int		i;

	i = -1;
	while (++i < XPM_NULL)
	{
		if (xpm_images[i].mlx_img)
			mlx_destroy_image(win.mlx_ptr, \
			xpm_images[i].mlx_img);
	}
}

int	close_game(void *p)
{
	t_game	*game;

	game = (t_game *)p;
	if (game->win.scr.mlx_img)
		mlx_destroy_image(game->win.mlx_ptr, \
		game->win.scr.mlx_img);
	destroy_xpms(game->win, game->xpm_images);
	destroy_animation_struct(game, &game->anim_h);
	destroy_animation_struct(game, &game->anim_h_light);
	destroy_marker_struct(game);
	destroy_map_struct(game);
	if (game->win.win_ptr)
		mlx_destroy_window(game->win.mlx_ptr, game->win.win_ptr);
	if (game->win.mlx_ptr)
		mlx_destroy_display(game->win.mlx_ptr);
	free(game);
	exit(0);
}
