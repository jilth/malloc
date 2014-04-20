/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:23:25 by noumazza          #+#    #+#             */
/*   Updated: 2013/11/30 15:42:42 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	d;
	int		ini_len;

	i = ft_strlen(dst);
	ini_len = i;
	d = (int)size - i - 1;
	if (i >= (int)size)
		return (ft_strlen(src) + size);
	size = 0;
	while ((unsigned int)ft_strlen(src) != size && d != size)
		dst[i++] = src[size++];
	dst[i] = '\0';
	return (ini_len + ft_strlen(src));
}
