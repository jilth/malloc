/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 03:51:54 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 19:34:52 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "malloc.h"
#include "libft.h"

t_glob	g_g;

void	*set_ptr(t_info info, void *mem)
{
	void	*ptr;

	ptr = write_size(info.size, mem);
	ptr = write_block_count(info.block_count, ptr);
	if (info.type > 3)
	{
		if (info.type == SMALL_N)
			info.type = SMALL;
		else if (info.type == TINY_N)
			info.type = TINY;
		else
			info.type = LARGE;
	}
	ptr = write_mem_pos(info.mem_pos, info.type, ptr);
	return (ptr);
}

void		my_zero(void *p, size_t n)
{
	char *tmp;

	tmp = (char *)p;
	while (--n != 0)
		tmp[n] = 0;
}

t_mem_inf	init_mem(int s_type, int size, int type)
{
	t_mem_inf	tmp;
	t_info		info;

	printf("INIT MEM type %d\n", type);
	g_g.max_allocs[type]++;
	tmp.mem = mmap(0, s_type, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	my_zero(tmp.mem, s_type);
	info.size = size;
	info.block_count = 0;
	info.mem_pos = 0;
	info.type = type;
	tmp.ptr = set_ptr(info, tmp.mem);
	tmp.mem_pos = 0;
	return (tmp);
}

void	*malloc(size_t size)
{
	void *ptr;

	if (size <= TINY_N)
		ptr = tiny_malloc(size);
	else if (size <= SMALL_N)
		ptr = small_malloc(size);
	else
		ptr = large_malloc(size);
	return (ptr);
}

int		main()
{
	int	t;

	char *p = (char *)malloc(14);
	show_alloc_mem();
	return 0;
}
