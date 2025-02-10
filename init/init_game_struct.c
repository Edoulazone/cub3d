/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:13:50 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	init_game_struct(t_game **game, t_pars *data)
{
	*game = (t_game *)malloc(sizeof(t_game));
	if (!*game)
		return (printf("Error: main game struct\n"), false);
	(*game)->win_w = WIN_W;
	(*game)->win_h = WIN_H;
	(*game)->fps = FPS;
	(*game)->state = home_screen;
	(*game)->created_at = gettimeofday_ms();
	(*game)->updated_at = gettimeofday_ms();
	(*game)->data = *data;
	return (true);
}
