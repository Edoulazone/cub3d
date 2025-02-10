/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:30:59 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 11:25:44 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	extension(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	while (arg && arg[i] && arg[i] != '.')
		i++;
	if (!arg[i] || arg[i] != '.')
		return (1);
	i++;
	if (!arg[i] || arg[i] != 'c' || !arg[i + 1] || arg[i + 1] != 'u'
			|| !arg[i + 2] || arg[i + 2] != 'b' || arg[i + 3])
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_pars	*data;

	if (argc != 2)
		return (write(1, "Wrong number of arguments\n", 26), 1);
	if (extension(argv[1]))
		return (write(1, "Wrong file format\n", 18), 1);
	data = malloc(sizeof(t_pars));
	init_pars(&data);
	parse_all(data, argv[1]);
	if (!init_project(&game, data))
		return (1);
	mlx_loop_hook(game->win.mlx_ptr, update, game);
	mlx_loop(game->win.mlx_ptr);
	return (0);
}
