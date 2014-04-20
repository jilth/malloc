/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 12:10:00 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 16:33:13 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*write_size(int size, void *ptr)
{
	int		i;
	int		v;
	char	bit;
	char	*tmp;

	tmp = (char *)ptr;
	i = -1;
	v = -1;
	while (++i < 32)
	{
		if (i % 8 == 0)
			v++;
		bit = size & 1 ? 1 : 0;
		size >>= 1;
		bit <<= (i % 8);
		tmp[v] |= bit;
	}
	ptr = (void *)tmp + (32 / 8);
	return (ptr);
}

void	*write_block_count(int block_count, void *ptr)
{
	int		i;
	int		v;
	char	bit;
	char	*tmp;

	i = -1;
	tmp = (char *)ptr;
	v = -1;
	while (++i < 16)
	{
		if (i % 8 == 0)
			v++;
		bit = block_count & 1 ? 1 : 0;
		block_count >>= 1;
		bit <<= (i % 8);
		tmp[v] |= bit;
	}
	ptr = (void *)tmp + 2;
	return (ptr);
}

void	*write_mem_pos(int mem_pos, int type, void *ptr)
{
	char	*tmp;

	tmp = (char *)ptr;
	tmp[0] = (unsigned char)mem_pos;
	tmp[1] = (unsigned char)type + 1;
	ptr = (void *)tmp + 2;
	return (ptr);
}
