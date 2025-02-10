/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:32:20 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_sprite	new_sprite(char *name, char *file_path, t_win *win)
{
	t_img	img;

	img = set_new_xpm(file_path, win);
	return ((t_sprite){NULL, NULL, ft_strdup(name), \
	ft_strdup(file_path), img, img.width, img.height});
}
