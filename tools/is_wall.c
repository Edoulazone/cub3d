/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:29:04 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	is_wall(int num)
{
	if (num == ID_WALL \
	|| num == ID_METAL \
	|| num == ID_METAL2 \
	|| num == ID_SCAFFOLD \
	|| num == ID_PIPE \
	|| num == ID_GRIDS)
		return (true);
	return (false);
}
