/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:30:31 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_rect(t_rect rect)
{
	int	i;
	int	j;

	i = 0;
	while (i < rect.h && i + rect.y < rect.img->height)
	{
		j = 0;
		while (j < rect.w && j + rect.x < rect.img->width)
		{
			img_pix_put(rect.img, j + rect.x, i + rect.y, rect.color);
			j++;
		}
		i++;
	}
}
