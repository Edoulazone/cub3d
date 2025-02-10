/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:23:19 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (start < (unsigned int)ft_strlen((char *)s))
	{
		while (s[start] != '\0' && i < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
	}
	str[i] = '\0';
	return (str);
}

char	*ft_subbuff(char *buff, int start, int len)
{
	int		i;
	char	*str;

	str = NULL;
	str = ft_strjoin(str, buff);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		buff[i] = str[start];
		i++;
		start++;
	}
	buff[i] = 0;
	free(str);
	return (buff);
}
