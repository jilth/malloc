/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 20:42:55 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:05:45 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

static void	rechex(size_t n)
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

void		puthex(size_t n)
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
	return (size);
}
