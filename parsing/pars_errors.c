/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:23:15 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/30 12:03:05 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_exit(t_pars *data, char *str)
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
	{
		if (data->tmp_map_h < data->map_h)
			free_tmp_map(data, &data->map);
		else
			free_map(data, &data->map);
	}
	free_colours(data);
	if (data)
		free(data);
	exit(1);
}

int	ft_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\0' && str[i] != '\n'
			&& str[i] != '\r' && str[i] != '\v' && str[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}

void	flood_fill(t_pars *d, int **map, int x, int y)
{
	if ((x < 0 || y < 0 || x >= d->map_w || y >= d->map_h) || map[y][x] == -1)
	{
		d->tmp_map_h++;
		ft_exit(d, "Map error");
	}
	if (map[y][x] == 1 || map[y][x] == -2)
		return ;
	map[y][x] = -2;
	flood_fill(d, map, x + 1, y);
	flood_fill(d, map, x - 1, y);
	flood_fill(d, map, x, y + 1);
	flood_fill(d, map, x, y - 1);
}

void	copy_map(t_pars *data, int ***target, int **source)
{
	int	x;
	int	y;

	(*target) = malloc(sizeof(int *) * data->map_h);
	if (!(*target))
		ft_exit(data, "Malloc failed");
	y = -1;
	while (++y < data->map_h)
	{
		(*target)[y] = malloc(sizeof(int) * data->map_w);
		if (!(*target)[y])
		{
			while (--y >= 0)
				free((*target)[y]);
			free(*target);
			ft_exit(data, "Malloc failed");
		}
	}
	y = -1;
	while (++y < data->map_h)
	{
		x = -1;
		while (++x < data->map_w)
			(*target)[y][x] = source[y][x];
	}
}

void	ft_errors(t_pars *d, char *str)
{
	int	**map_copy;

	map_copy = NULL;
	if (!d->no || !d->so || !d->we || !d->ea)
		ft_exit(d, "Texture informations missing");
	if (!d->c || !d->f)
		ft_exit2(d, "Colour informations missing");
	copy_map(d, &map_copy, d->map);
	if (!str)
	{
		if (!d->start_dir || !d->start_x || !d->start_y)
			ft_exit2(d, "Player informations inexistant or wrong");
		if (d->empty_line)
			ft_exit2(d, "Empty line in map");
		if (d->wrongchar)
			ft_exit(d, "Wrong character in map");
		flood_fill(d, map_copy, d->start_x, d->start_y);
		free_map(d, &map_copy);
	}
}
