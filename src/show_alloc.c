/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 12:18:37 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 20:38:55 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

static void rechex(size_t n)
{
	int	i;

	i = n / 16;
	if (i)
		rechex(n / 16);
	i = n % 16;
	if (i >= 0 && i <= 9)
		ft_putchar(i + '0');
	else
		ft_putchar(i - 10 + 'A');
}

void	puthex(size_t n)
{
	ft_putstr("0x");
	rechex(n);
}

void		print_nbr(int n)
{
	int	i;

	i = n / 10;
	if (i)
		print_nbr(n / 10);
	i = n % 10;
	if (i < 0)
		i *= -1;
	ft_putchar(i + '0');
}

int			print_ptr(void *ptr)
{
	int		size;

	size = get_size(ptr);
	puthex((size_t)ptr);
	ft_putstr(" - ");
	puthex((size_t)(ptr + size));
	ft_putstr(" : ");
	print_nbr(size);
	ft_putendl(" octets");
	return (0);
}

static int	print_tiny()
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

static int	print_small()
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

static int	print_large()
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

void	show_alloc_mem()
{
	int	tot;

	tot = print_tiny();
/*	tot += print_small();
	tot += print_large();
	ft_putstr("Total : ");
	ft_putnbr(tot);
	ft_putendl(" octets");*/
}
