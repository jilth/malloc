#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/09 02:27:06 by noumazza          #+#    #+#              #
#    Updated: 2014/04/20 21:18:23 by noumazza         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SHELL := tcsh

NAME := $(shell echo libft_malloc_$$HOSTTYPE.so)

LNNAME = libft_malloc.so

LIBFT = ./libft

DIR = $(LIBFT) ./inc/

DIRI = $(addprefix -I, $(DIR))

FLAGS = -Wall -Wextra -shared

SRC = free.c get_funcs.c large_malloc.c malloc.c realloc.c show_alloc.c \
		small_malloc.c tiny_malloc.c write_funcs.c misc_func.c

OBJ = $(SRC:.c=.o)

TRASH = $(SRC:.c=.c~)

HFILE = ./inc/

SRCDIR = ./src/

OBJDIR = ./obj/

FILES = Makefile auteur src inc libft $(LNNAME)

OBJS = $(addprefix obj/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p $(@D)
	$(MAKE) -C $(LIBFT)
	gcc $(FLAGS) -L$(LIBFT) -lft -o $@ $^$
	rm -f $(LNNAME)
	ln -s $(NAME) libft_malloc.so

obj/%.o: $(SRCDIR)%.c $(HILE)
	@mkdir -p $(@D)
	gcc $(FLAGS) -c $(DIRI) $< -o $@

clean:
	rm -f $(LNNAME)
	rm -f $(OBJ)
	rm -f $(TRASH)

fclean: clean
	@rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: clean all re fclean push
