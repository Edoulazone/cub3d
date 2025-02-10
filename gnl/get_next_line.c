/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:22:41 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_copy(char **line, char **buff, int start)
{
	char	*temp;
	char	*line_temp;

	if (start >= 0)
	{
		temp = ft_substr(*buff, 0, start);
		line_temp = *line;
		*line = ft_strjoin(*line, temp);
		free(temp);
		free(line_temp);
		*buff = ft_subbuff(*buff, start + 1, (ft_strlen(*buff) - start));
		return (0);
	}
	else
	{
		temp = NULL;
		if (*line)
			temp = *line;
		*line = ft_strjoin(*line, *buff);
		if (temp)
			free(temp);
		return (1);
	}
	return (-1);
}

int	ft_eof(int ret, char **buff, char **line)
{
	if (ret == -1)
		return (-1);
	free(*buff);
	*buff = NULL;
	if (*line == NULL)
	{
		*line = malloc(sizeof(char) * 1);
		*line[0] = 0;
	}
	return (0);
}

static int	gnl_the_hell_of_a_nation(int ret, int fd, char **line, char **buff)
{
	ret = read(fd, *buff, BUFFER_SIZE);
	while (ret > 0)
	{
		(*buff)[ret] = '\0';
		if (!ft_copy(line, buff, ft_check(*buff)))
			return (1);
		ret = read(fd, *buff, BUFFER_SIZE);
	}
	if (ret <= 0)
		return (ft_eof(ret, buff, line));
	return (1);
}

int	get_next_line(int fd, char **line, t_pars *data)
{
	static char	*buff = NULL;
	int			ret;

	if (data->error == 1 && buff)
	{
		free(buff);
		return (0);
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	ret = 1;
	if (buff)
		ret = ft_copy(line, &buff, ft_check(buff));
	if (ret == 0)
		return (1);
	if (!buff)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
			return (-1);
	}
	return (gnl_the_hell_of_a_nation(ret, fd, line, &buff));
}
