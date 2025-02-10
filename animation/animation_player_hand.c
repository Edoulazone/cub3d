/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_player_hand.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:53:27 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	update_animatiom_frames(t_animation *a, t_animation *b)
{
	a->current_frame_num++;
	b->current_frame_num++;
	a->current_frame = ((t_list *)a->current_frame)->next;
	b->current_frame = ((t_list *)b->current_frame)->next;
	if (a->current_frame == NULL)
	{
		a->current_frame_num = 0;
		b->current_frame_num = 0;
		a->current_frame = a->sequence;
		b->current_frame = b->sequence;
	}
	a->tmp_delay = 0;
	b->tmp_delay = 0;
}

void	player_hand(t_game *game)
{
	t_animation	*a;
	t_animation	*b;

	a = &game->anim_h;
	b = &game->anim_h_light;
	if (game->keys.w || game->keys.a || game->keys.s || game->keys.d)
	{
		if (++a->tmp_delay >= a->delay && ++b->tmp_delay >= b->delay)
			update_animatiom_frames(a, b);
	}
	if (game->keys.e || game->keys.mouse_1)
		put_img_to_img(&game->win.scr, \
		((t_list *)b->current_frame)->content, b->x, b->y);
	else
		put_img_to_img(&game->win.scr, \
		((t_list *)a->current_frame)->content, a->x, a->y);
}
