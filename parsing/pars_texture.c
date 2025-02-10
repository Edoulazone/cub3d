/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:11:07 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/30 12:08:40 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	get_text_len(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '.')
		i++;
	while (str[i])
	{
		i++;
		j++;
	}
	return (j);
}

void	find_texture(t_pars *data, char **text, char *str, int j)
{
	int	i;

	i = 0;
	if (*text || !det_c(str, '.') || !det_c(str, '/'))
		data->error = 1;
	while (str && str[j] != '.')
	{
		if (str[j] != 32)
			data->error = 1;
		j++;
	}
	*text = malloc(get_text_len(str) + 1);
	if (!*text)
		ft_exit(data, "Malloc failed\n");
	while (str && str[j])
	{
		(*text)[i] = str[j];
		i++;
		j++;
	}
	(*text)[i] = '\0';
}

void	texture_error_check(t_pars *data, char *str)
{
	if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W' && str[0] != 'E'
		&& str[0] != 'F' && str[0] != 'C' && str[0] > 65 && str[0] < 122)
		data->error = 1;
}

void	get_texture(t_pars *data, char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
	{
		if (data->no)
			ft_exit(data, "Two NO textures were given");
		find_texture(data, &data->no, str, 2);
	}
	else if (str[0] == 'S' && str[1] == 'O')
	{
		if (data->so)
			ft_exit(data, "Two SO textures were given");
		find_texture(data, &data->so, str, 2);
	}
	else if (str[0] == 'W' && str[1] == 'E')
	{
		if (data->we)
			ft_exit(data, "Two WE textures were given");
		find_texture(data, &data->we, str, 2);
	}
	else if (str[0] == 'E' && str[1] == 'A')
	{
		if (data->ea)
			ft_exit(data, "Two EA textures were given");
		find_texture(data, &data->ea, str, 2);
	}
	texture_error_check(data, str);
}
