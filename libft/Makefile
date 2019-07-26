# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/27 14:25:41 by rrhaenys          #+#    #+#              #
#    Updated: 2019/06/28 16:52:18 by rrhaenys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
MAKEFLAGS += --no-print-directory
MAKEFLAGS += -s
endif

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC_DIR = src/
SRC_FIL = $(shell ls src | grep -E "ft_.+\.c")
SRC_COUNT = $(shell ls src | grep -E "ft_.+\.c" | wc -l)
SRCS = $(addprefix  $(SRC_DIR), $(SRC_FIL))
NUM=1
INCLUDE = -Iincludes
COMMAND = gcc
LIBFT_DIR = src/libftr/
LIBFT_FIL = $(shell ls src/libftr | grep -E "ft_.+\.c")
LIBFT_SRCS = $(addprefix  $(LIBFT_DIR), $(LIBFT_FIL))
LIBFT_OBJ	= $(LIBFT_SRCS:.c=.o)
OBJ	= $(SRCS:.c=.o) $(LIBFT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	# @bash -c "echo -en '\r                                 '"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

.c.o:
	@printf "\033[1;31m"
	# @bash -c "echo -en '\r$<                                  '"
	@printf "\033[0m"
	@$(COMMAND) $(FLAGS) $(INCLUDE) -g -c -o $@ $<

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f src/*.o
	@/bin/rm -f src/libftr/*.o

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f test

re: fclean all

.PHONY: clean fclean all re
