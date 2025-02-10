/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:32:02 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* Behave as a game loop
** It updates regarding the fps set in the game struct
*/
int	update(t_game *game)
{
	if (timestamp_in_ms(game) - game->updated_at \
	>= (uint64_t)(1000 / game->fps))
	{
		game->updated_at = timestamp_in_ms(game);
		handle_keys(game);
		if (game->state == home_screen)
			return (0);
		layout_game_screen(game);
	}
	return (0);
}
