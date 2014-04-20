/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:16 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:16 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			get_rest(char **s1, char **line)
{
	char		*new_rest;
	char		*tmp;

	if (!(*s1))
		*line = ft_strdup("");
	else
		new_rest = ft_strchr(*s1, '\n');
	{
		if (new_rest)
		{
			*line = ft_strsub(*s1, 0, new_rest - *s1);
			(*line)[new_rest - *s1] = '\0';
			tmp = *s1;
			*s1 = ft_strdup(new_rest + 1);
			free(tmp);
			return (1);
		}
		*line = ft_strjoin("", *s1);
		free(*s1);
		*s1 = NULL;
	}
	return (0);
}

int			get_line(char *buf, char **line, char **left_over)
{
	char	*tmp;
	char	*tmp2;
	char	*new_rest;

	new_rest = ft_strchr(buf, '\n');
	tmp2 = *line;
	if (new_rest)
	{
		*left_over = ft_strdup(new_rest + 1);
		tmp = ft_strsub(buf, 0, new_rest - buf);
		tmp[new_rest - buf] = '\0';
		*line = ft_strjoin(tmp2, tmp);
		free(tmp2);
		free(tmp);
		return (1);
	}
	*line = ft_strjoin(tmp2, buf);
	return (0);
}

int			ft_get_next_line(int const fd, char **line)
{
	char			buf[BSIZE + 1];
	int				c;
	static char		*left_over = NULL;

	if (get_rest(&left_over, line))
		return (1);
	if (fd < 0)
		return (-1);
	while ((c = read(fd, buf, BSIZE)) > 0)
	{
		buf[c] = '\0';
		if (get_line(buf, line, &left_over))
			return (1);
	}
	return (c);
}
