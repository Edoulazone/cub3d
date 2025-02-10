/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:20:46 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/30 11:38:08 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_number(t_pars *data, char c)
{
	if (!c)
		return (0);
	if (c >= '0' && c <= '9')
		return (1);
	if (c != ',' && c != ' ')
		ft_exit(data, "Colour code is wrong");
	return (0);
}

void	ft_exit2(t_pars *data, char *str)
{
	if (str && str[0])
	{
		write (1, "Error: ", 7);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->map)
		free_map(data, &data->map);
	free_colours(data);
	if (data)
		free(data);
	exit(1);
}
