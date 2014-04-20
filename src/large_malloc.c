/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 15:56:18 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 16:03:59 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*large_malloc(int size)
{
	static int	block_count = -1;
	int			mult;

	mult = (size / getpagesize()) + (size % getpagesize());
	if (block_count == -1)
	{
		g_g.max_allocs[LARGE] = 0;
		g_g.memory[0].mem_large = init_mem(getpagesize() * mult, size, LARGE);
		block_count = 0;
	}
	else
	{
		g_g.memory[++block_count].mem_large =
							init_mem(getpagesize() * mult, size, LARGE);
	}
	return (g_g.memory[block_count].mem_large.ptr);
}
