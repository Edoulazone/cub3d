/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pars_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:19:57 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_pars(t_pars **data)
{
	(*data)->map = NULL;
	(*data)->error = 0;
	(*data)->map_w = 0;
	(*data)->map_h = 0;
	(*data)->empty_line = 0;
	(*data)->wrongchar = 0;
	(*data)->in_map = 0;
	(*data)->start_x = 0;
	(*data)->start_y = 0;
	(*data)->start_dir = 0;
	(*data)->no = NULL;
	(*data)->so = NULL;
	(*data)->we = NULL;
	(*data)->ea = NULL;
	(*data)->f = 0;
	(*data)->c = 0;
	(*data)->fr = NULL;
	(*data)->fg = NULL;
	(*data)->fb = NULL;
	(*data)->cr = NULL;
	(*data)->cg = NULL;
	(*data)->cb = NULL;
}
