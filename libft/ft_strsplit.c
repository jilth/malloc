/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:19 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:19 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbr_strs(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != c && *(s - 1) != c)
			i++;
		++s;
	}
	return (i);
}

static int		len(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s++)
		i++;
	return (i);
}

static char		*fill_str(char const *s, char c)
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = (char *)malloc(len(s, c) + 1);
	if (!new_s)
		return (NULL);
	while (*s && *s != c)
		new_s[i++] = *s++;
	new_s[i] = '\0';
	return (new_s);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new_str_t;
	int		flag;
	int		count;

	count = 0;
	if (s)
	{
		flag = 1;
		new_str_t = (char **)malloc((nbr_strs(s, c) + 1) * sizeof(char *));
		while (*s++ != '\0' && new_str_t)
		{
			if (*(s - 1) != c && flag)
			{
				if ((new_str_t[count++] = fill_str(s - 1, c)) == NULL)
					return (NULL);
				flag = 0;
			}
			else if (*(s - 1) == c)
				flag = 1;
		}
		new_str_t[count] = NULL;
		return (new_str_t);
	}
	return (NULL);
}
