/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 12:10:56 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 20:06:21 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		get_size(void *ptr)
{
	int		inc[2];
	int		res;
	int		bit;
	char	s;
	char	*tmp;

	tmp = (char *)ptr - 8;
	inc[0] = -1;
	inc[1] = -1;
	res = 0;
	while (++inc[0] < 32)
	{
		if (inc[0] % 8 == 0)
			s = tmp[++inc[1]];
		bit = s & 1 ? 1 : 0;
		s >>= 1;
		bit <<= inc[0];
		res |= bit;
	}
	return (res);
}

int		get_block_count(void *ptr)
{
	int		inc[2];
	int		bit;
	int		res;
	char	s;
	char	*tmp;

	inc[0] = -1;
	tmp = (char *)ptr - 4;
	inc[1] = -1;
	res = 0;
	while (++inc[0] < 16)
	{
		if (inc[0] % 8 == 0)
			s = tmp[++inc[1]];
		bit = s & 1 ? 1 : 0;
		s >>= 1;
		bit <<= inc[0];
		res |= bit;
	}
	return (res);
}

int		get_alloc_flag(void *ptr)
{
	char	res;
	char	*tmp;

	tmp = (char *)ptr - 1;
	res = tmp[0];
	return (res);
}

int		get_mem_pos(void *ptr)
{
	char	res;
	char	*tmp;

	tmp = (char *)ptr - 2;
	res = tmp[0];
	return (res);
}
