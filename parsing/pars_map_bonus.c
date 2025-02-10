/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:13:08 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/30 10:52:00 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	cast_char(t_pars *data, char c)
{
	int	ret;

	ret = 0;
	if (c > '8' || c < '0')
		ft_exit(data, "Wrong character in map 1 bonus");
	ret = c - 48;
	return (ret);
}

int	start(t_pars *data, int i, int j, char c)
{
	static int	checker = 0;

	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (checker)
			ft_exit(data, "At least two start positions");
		data->start_dir = c;
		data->start_x = j;
		data->start_y = i;
		checker = 1;
		return (1);
	}
	return (0);
}

void	create_map(t_pars *data, char *str, int michel)
{
	int			i;
	static int	j = 0;

	i = -1;
	data->tmp_map_h = michel;
	data->map[j] = malloc(sizeof(int) * (data->map_w));
	if (!(data->map[j]))
		return ;
	while (str[++i])
	{
		if (start(data, j, i, str[i]))
			data->map[j][i] = 0;
		else if (str[i] == 32)
			data->map[j][i] = -1;
		else
			data->map[j][i] = cast_char(data, str[i]);
	}
	while (i < (data->map_w))
		data->map[j][i++] = -1;
	j++;
}

int	is_map(t_pars *data, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (det_c(str, '1') || det_c(str, '0') || det_c(str, '2') || det_c(str, '3')
		|| det_c(str, '4') || det_c(str, '5') || det_c(str, '6')
		|| det_c(str, '7') || det_c(str, '8'))
	{
		while (str[i])
		{
			if (is_special(str[i]))
			{
				if (data->in_map == 1)
				{
					data->tmp_map_h++;
					ft_exit(data, "Wrong character in map 2 bonus");
				}
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

void	map_pars(t_pars *data, char *file)
{
	int			check;
	int			fd;
	static char	*str;
	int			i;

	i = 0;
	check = 1;
	str = NULL;
	fd = open(file, O_RDONLY);
	data->map = malloc(sizeof(int *) * data->map_h);
	if (!(data->map))
		return ;
	while (check)
	{
		check = get_next_line(fd, &str, data);
		if (data->in_map && !ft_empty_line(str) && i < data->map_h)
			data->empty_line = 1;
		data->in_map = is_map(data, str);
		if (data->in_map)
			create_map(data, str, i++);
		free(str);
	}
	close(fd);
}
