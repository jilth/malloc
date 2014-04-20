/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 06:11:37 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 18:59:41 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <stdio.h>
# include <unistd.h>

# define TINY_N 16
# define TINY_S 24
# define TINY_MAX 170
# define TINY_TOT 4096
# define SMALL_N 512
# define SMALL_S 520
# define SMALL_MAX 102
# define SMALL_TOT 53248
# define MAX_BLOCKS 131071

typedef struct s_mem_inf	t_mem_inf;
typedef struct s_info		t_info;
typedef struct s_memory		t_memory;
typedef struct s_glob		t_glob;

struct s_mem_inf
{
	void			*mem;
	void			*ptr;
	int				mem_pos;
};

enum	s_type
{
	TINY = 0,
	SMALL = 1,
	LARGE = 2
};

struct s_info
{
	int	block_count;
	int	mem_pos;
	int	size;
	int	type;
};

struct s_memory
{
	t_mem_inf	mem_tiny;
	t_mem_inf	mem_small;
	t_mem_inf	mem_large;
};

struct s_glob
{
	int			max_allocs[3];
	t_memory	memory[MAX_BLOCKS];
};

extern t_glob	g_g;

void		*scan_mem(int block_count, int size, int type, void *ptr);
void		*small_malloc(int size);
void		*tiny_malloc(int size);
void		*large_malloc(int size);
void		*set_ptr(t_info info, void *mem);
t_mem_inf	init_mem(int s_type, int size, int type);
void		*write_size(int size, void *ptr);
void		*write_block_count(int block_count, void *ptr);
void		*write_mem_pos(int mem_pos, int type, void *ptr);
int			get_size(void *ptr);
int			get_block_count(void *ptr);
int			get_alloc_flag(void *ptr);
int			get_mem_pos(void *ptr);
void		free(void *ptr);
void		*realloc(void *ptr, size_t size);
void		*malloc(size_t size);
void		show_alloc_mem();
int			check_mem(int block_count, int type, int mem_pos, void *ptr);

#endif
