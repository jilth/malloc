/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 09:59:42 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 19:19:13 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*tiny_malloc(int size)
{
	static int	block_count = -1;

	if (block_count == -1)
	{
		g_g.max_allocs[TINY] = 0;
		g_g.memory[0].mem_tiny = init_mem(getpagesize(), size, TINY);
		block_count = 0;
	}
	else
	{
		g_g.memory[block_count].mem_tiny.mem_pos++;
		if (g_g.memory[block_count].mem_tiny.mem_pos == TINY_MAX)
			g_g.memory[++block_count].mem_tiny = \
									init_mem(getpagesize(), size, TINY);
		else
			g_g.memory[block_count].mem_tiny.ptr = \
				scan_mem(block_count, size, \
					TINY_N, g_g.memory[block_count].mem_tiny.mem);
	}
	return (g_g.memory[block_count].mem_tiny.ptr);
}
