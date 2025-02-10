/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:05:49 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/30 11:23:44 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	parse_all(t_pars *data, char *file)
{
	int		fd;
	int		checker;
	char	*str;

	checker = 1;
	str = NULL;
	fd = check_fd(data, file);
	while (checker)
	{
		checker = get_next_line(fd, &str, data);
		if (data->error == 1)
			ft_errors(data, "Problem with map");
		pars_colours(data, str);
		get_texture(data, str);
		map_check(data, str);
		free(str);
	}
	close (fd);
	if (!data->map_w || !data->map_h)
		ft_exit(data, "No map given");
	map_pars(data, file);
	ft_errors(data, NULL);
}
