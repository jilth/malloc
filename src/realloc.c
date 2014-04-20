/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 17:22:23 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 20:42:28 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int			check_mem(int block_count, int type, int mem_pos, void *ptr)
{
	void	*mem;

	if (type == TINY)
		mem = g_g.memory[block_count].mem_tiny.mem + 8 \
			+ (mem_pos * (TINY_N + 8));
	else if (type == SMALL)
		mem = g_g.memory[block_count].mem_small.mem + 8 \
			+ (mem_pos * (SMALL_N + 8));
	else
		mem = g_g.memory[block_count].mem_large.mem;
	if (mem != ptr)
		return (0);
	return (1);
}

static void	*cpy_to_new_size(void *ptr, int size, int dst)
{
	void	*new_ptr;
	char	*tmp_a;
	char	*tmp_b;
	int		i;
	int		len;

	if (dst == 1)
		new_ptr = small_malloc(size);
	else
		new_ptr = large_malloc(size);
	tmp_a = (char *)new_ptr;
	i = -1;
	len = get_size(ptr);
	tmp_b = (char *)ptr;
	while (++i < len)
		tmp_a[i] = tmp_b[i];
	free(ptr);
	return (new_ptr);
}

void		*realloc(void *ptr, size_t size)
{
	t_info	info;

	info.type = get_alloc_flag(ptr) - 1;
	info.mem_pos = get_mem_pos(ptr);
	info.block_count = get_block_count(ptr);
	if (!check_mem(info.block_count, info.type, info.mem_pos, ptr))
		return (NULL);
	if (info.type == TINY && size <= TINY_N)
		return (ptr);
	if (info.type == SMALL && size <= SMALL_N)
		return (ptr);
	if (info.type == TINY && size <= SMALL_N)
		return (cpy_to_new_size(ptr, size, 1));
	return (cpy_to_new_size(ptr, size, 2));
}
