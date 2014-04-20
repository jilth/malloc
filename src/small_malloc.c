/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 15:39:23 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 16:21:38 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*scan_mem(int block_count, int size, int type, void *ptr)
{
	int			mem_pos;
	t_info		info;

	mem_pos = 0;
	info.size = size;
	info.block_count = block_count;
	info.type = type;
	while (42)
	{
		ptr += 8;
		if (!get_alloc_flag(ptr))
		{
			ptr -= 8;
			info.mem_pos = mem_pos;
			ptr = set_ptr(info , ptr);
			return (ptr);
		}
		ptr += type;
		mem_pos++;
	}
}

void	*small_malloc(int size)
{
	static int	block_count = -1;

	if (block_count == -1)
	{
		g_g.max_allocs[SMALL] = 0;
		g_g.memory[0].mem_small = init_mem(getpagesize() * 13, size, SMALL);
		block_count = 0;
	}
	else
	{
		g_g.memory[block_count].mem_small.mem_pos++;
		if (g_g.memory[block_count].mem_small.mem_pos == SMALL_MAX)
			g_g.memory[++block_count].mem_small = \
									init_mem(getpagesize() * 13, size, SMALL);
		else
			g_g.memory[block_count].mem_small.ptr = \
				scan_mem(block_count, size, \
					SMALL_N, g_g.memory[block_count].mem_small.mem);
	}
	return (g_g.memory[block_count].mem_small.ptr);
}
