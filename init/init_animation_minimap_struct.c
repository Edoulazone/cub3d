/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animation_minimap_struct.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:20:03 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static bool	create_frame_img(t_marker *marker, t_sprite s, \
	t_sprite_slice_data data)
{
	t_img		frame_img;
	int			y;
	int			x;

	frame_img = new_img(data.width, data.height, s.sprite_img.win);
	if (frame_img.mlx_img == NULL)
	{
		free(marker);
		return (false);
	}
	y = -1;
	while (++y < data.height)
	{
		x = -1;
		while (++x < data.width)
			copy_pixel_img((t_copy_pix){s.sprite_img, data.x + x, \
			data.y + y, frame_img, x, y});
	}
	marker->frame = frame_img;
	return (true);
}

/*	To create one frame, it fills the info and link it to the lst
*	1. init marker
*	2. set min angle
*	3. init an img (inside create_frame_img)
*		4. set the img (copy memory equivalent to only one marker)
*		5. create a lst node linked to the main list
*	The marker obj is a lst with
	\_	img -> single img extracted from the main sprite(holding the 24 move)
	 \_	min angle -> float that describe the angle where arrow img points to
*/
static bool	minimap_add_frame(t_lst **a, t_sprite s, \
	t_sprite_slice_data data, int i)
{
	t_marker	*marker;

	marker = (t_marker *)ft_calloc(sizeof(t_marker), 1);
	if (!marker)
		return (false);
	marker->min_angle = (i * 15) - 7.5;
	if (marker->min_angle < 0)
		marker->min_angle += 360;
	create_frame_img(marker, s, data);
	if (!*a)
		*a = lst_new_double(marker);
	else
		lstadd_back_double(a, lst_new_double(marker));
	return (true);
}

/*	This function create a lst of frames
*	for the animation.
*	it creates node linked each other (prev and next)
*	and add a content that is a marker object
*/
static t_lst	*minimap_sprite_slicer(t_sprite s, int frames)
{
	int					i;
	t_lst				*anim;
	t_sprite_slice_data	data;

	data.width = 32;
	data.height = 32;
	data.x = 0;
	data.y = 0;
	anim = NULL;
	i = 0;
	while (i < frames)
	{
		if (!minimap_add_frame(&anim, s, data, i))
			return (NULL);
		data.x += data.width;
		if (data.x >= s.width)
		{
			data.x = 0;
			data.y += data.height;
		}
		i++;
	}
	return (anim);
}

/*
*	1. We create the sprite object with new_sprite
*	2. Slice the sprite for each frames and
*		create the animation sequence list 
*		(24 because we divide the circle to have 15deg coverage per frame)
*	3. Make the list circular (link last to first)
*/
bool	init_anim_minimap(t_game *game)
{
	t_lst	*last_node;

	game->map.pos_sprite = \
	new_sprite("marker", "assets/marker.xpm", &game->win);
	if (game->map.pos_sprite.sprite_img.mlx_img == NULL \
		|| game->map.pos_sprite.file_path == NULL \
		|| game->map.pos_sprite.name == NULL)
		return (false);
	game->map.pos_sprite.anim = minimap_sprite_slicer(game->map.pos_sprite, 24);
	game->map.pos_sprite.cur_node = game->map.pos_sprite.anim;
	last_node = lstlast((t_lst *)game->map.pos_sprite.anim);
	((t_lst *)game->map.pos_sprite.anim)->prev = last_node;
	last_node->next = (t_lst *)game->map.pos_sprite.anim;
	return (true);
}
