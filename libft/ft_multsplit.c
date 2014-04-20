/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:17 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:35:36 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_c(char c, char *split_chars)
{
	int		i;

	i = -1;
	while (split_chars[++i])
	{
		if (c == split_chars[i])
			return (0);
	}
	return (1);
}

static int	nbr_strs(char const *s, char *split_c)
{
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	while (*s)
	{
		if (check_c(*s, split_c) && flag)
			i++;
		flag = !check_c(*s, split_c) ? 1 : 0;
		++s;
	}
	return (i);
}

static int	len(char const *s, char *split_c)
{
	int	i;

	i = 0;
	while (check_c(*s, split_c) && *s++)
		i++;
	return (i);
}

static char	*fill_str(char const *s, char *split_c)
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = (char *)malloc(len(s, split_c) + 1);
	if (!new_s)
		return (NULL);
	while (*s && check_c(*s, split_c))
		new_s[i++] = *s++;
	new_s[i] = '\0';
	return (new_s);
}

char		**ft_multsplit(char const *s, char *split_c)
{
	char	**new_str_t;
	int		flag;
	int		count;

	count = 0;
	if (s)
	{
		new_str_t = (char **)malloc((nbr_strs(s, split_c) + 1)
						* sizeof(char *));
		flag = 1;
		while (*s++ != '\0' && new_str_t)
		{
			if (check_c(*(s - 1), split_c) && flag)
			{
				if ((new_str_t[count++] = fill_str(s - 1, split_c)) == NULL)
					return (NULL);
				flag = 0;
			}
			else if (!(check_c(*(s - 1), split_c)))
				flag = 1;
		}
		new_str_t[count] = NULL;
		return (new_str_t);
	}
	return (NULL);
}
