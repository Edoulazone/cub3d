/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animation_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:13:46 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/17 22:40:43 by jveirman         ###   ########.fr       */
/*     
                                                                       */
/* ************************************************************************** */

#include "../cub3D.h"

bool	init_animation_struct(t_game *game)
{
	if (!init_anim_minimap(game))
		return (false);
	if (!init_anim_hand(game, "assets/player_hand.xpm", &game->anim_h))
		return (false);
	if (!init_anim_hand(game, "assets/player_hand_light.xpm", \
		&game->anim_h_light))
		return (false);
	return (true);
}
