/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:18 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:26:52 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))

{
	int			i;
	char		*new_s;

	if (s && f)
	{
		i = 0;
		new_s = (char *)malloc(ft_strlen(s) * sizeof(char));
		while (s[i] != '\0')
		{
			new_s[i] = (*f)(s[i]);
			i++;
		}
		return (new_s);
	}
	return (NULL);
}
