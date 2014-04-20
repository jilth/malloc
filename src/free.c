/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 16:11:22 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 20:41:07 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static	void	change_alloc_flag(void *ptr)
{
	char	*tmp;

	tmp = (char *)ptr - 1;
	tmp[0] = 0;
}

void			free(void *ptr)
{
	t_info	info;

	if (ptr == NULL)
		return ;
	info.type = get_alloc_flag(ptr) - 1;
	info.mem_pos = get_mem_pos(ptr);
	info.block_count = get_block_count(ptr);
	if (!check_mem(info.block_count, info.type, info.mem_pos, ptr))
		return ;
	change_alloc_flag(ptr);
	if (info.type == LARGE)
	{
		info.size = get_size(ptr);
		munmap(ptr, info.size);
		return ;
	}
}
