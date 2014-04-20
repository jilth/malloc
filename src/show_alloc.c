/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 12:18:37 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:05:18 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

static int	print_tiny(void)
{
	int		i;
	int		v;
	int		tot;
	void	*ptr;

	ft_putstr("TINY : ");
	puthex((size_t)(g_g.memory[0].mem_tiny.mem));
	ft_putchar('\n');
	i = -1;
	tot = 0;
	while (++i < g_g.max_allocs[TINY])
	{
		v = -1;
		ptr = g_g.memory[i].mem_tiny.mem;
		while (++v < TINY_MAX)
		{
			ptr += 8;
			if (get_alloc_flag(ptr))
				tot += print_ptr(ptr);
			ptr += TINY_N;
		}
	}
	return (tot);
}

static int	print_small(void)
{
	int		i;
	int		v;
	int		tot;
	void	*ptr;

	ft_putstr("SMALL : ");
	puthex((size_t)(g_g.memory[0].mem_small.mem));
	ft_putchar('\n');
	i = -1;
	tot = 0;
	while (++i < g_g.max_allocs[SMALL])
	{
		v = -1;
		ptr = g_g.memory[i].mem_small.mem;
		while (++v < SMALL_MAX)
		{
			ptr += 8;
			if (get_alloc_flag(ptr))
				tot += print_ptr(ptr);
			ptr += SMALL_N;
		}
	}
	return (tot);
}

static int	print_large(void)
{
	int		i;
	int		tot;
	void	*ptr;

	ft_putstr("LARGE : ");
	puthex((size_t)(g_g.memory[0].mem_large.mem));
	ft_putchar('\n');
	i = -1;
	tot = 0;
	while (++i < g_g.max_allocs[LARGE])
	{
		ptr = g_g.memory[i].mem_large.mem;
		ptr += 8;
		if (get_alloc_flag(ptr))
			tot += print_ptr(ptr);
	}
	return (tot);
}

void		show_alloc_mem(void)
{
	int	tot;

	tot = print_tiny();
	tot += print_small();
	tot += print_large();
	ft_putstr("Total : ");
	print_nbr(tot);
	ft_putendl(" octets");
}
