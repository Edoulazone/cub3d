/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_colours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:13:05 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/30 12:10:01 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	malloc_colour(t_pars *data, char flag)
{
	if (flag == 'c')
	{
		data->cr = malloc(100);
		if (!data->cr)
			ft_exit(data, "Malloc failed");
		data->cg = malloc(100);
		if (!data->cg)
			ft_exit(data, "Malloc failed");
		data->cb = malloc(100);
		if (!data->cb)
			ft_exit(data, "Malloc failed");
	}
	else if (flag == 'f')
	{
		data->fr = malloc(100);
		if (!data->fr)
			ft_exit(data, "Malloc failed");
		data->fg = malloc(100);
		if (!data->fg)
			ft_exit(data, "Malloc failed");
		data->fb = malloc(100);
		if (!data->fb)
			ft_exit(data, "Malloc failed");
	}
}

int	rh(int r, int g, int b, t_pars *data)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_exit(data, "RGB values must be between 0 and 255");
	return ((r << 16) | (g << 8) | b);
}

void	create_colour_c(t_pars *d, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == 'C')
		i++;
	while (!is_number(d, str[i]))
		i++;
	while (is_number(d, str[i]))
		d->cr[j++] = str[i++];
	d->cr[j] = '\0';
	while (!is_number(d, str[i]))
		i++;
	j = 0;
	while (is_number(d, str[i]))
		d->cg[j++] = str[i++];
	d->cg[j] = '\0';
	while (!is_number(d, str[i]))
		i++;
	j = 0;
	while (is_number(d, str[i]))
		d->cb[j++] = str[i++];
	d->cb[j] = '\0';
	d->c = rh((int)ft_atoi(d->cr), (int)ft_atoi(d->cg), (int)ft_atoi(d->cb), d);
}

void	create_colour_f(t_pars *d, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == 'F')
		i++;
	while (!is_number(d, str[i]))
		i++;
	while (is_number(d, str[i]))
		d->fr[j++] = str[i++];
	d->fr[j] = '\0';
	while (!is_number(d, str[i]))
		i++;
	j = 0;
	while (is_number(d, str[i]))
		d->fg[j++] = str[i++];
	d->fg[j] = '\0';
	while (!is_number(d, str[i]))
		i++;
	j = 0;
	while (is_number(d, str[i]))
		d->fb[j++] = str[i++];
	d->fb[j] = '\0';
	d->f = rh(ft_atoi(d->fr), ft_atoi(d->fg), ft_atoi(d->fb), d);
}

void	pars_colours(t_pars *data, char *str)
{
	if (str && str[0] == 'F' && str[1] && str[1] == 32)
	{
		if (data->f)
			ft_exit(data, "Two floor colours were given");
		malloc_colour(data, 'f');
		create_colour_f(data, str);
	}
	else if (str && str[0] == 'C' && str[1] && str[1] == 32)
	{
		if (data->c)
			ft_exit(data, "Two floor colours were given");
		malloc_colour(data, 'c');
		create_colour_c(data, str);
	}
}
