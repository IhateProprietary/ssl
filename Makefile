#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jye <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 19:47:40 by jye               #+#    #+#              #
#    Updated: 2019/03/22 16:31:44 by jye              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

SRC = decode encode internal_comp final ft_getopt_long ft_getopt_long1 hash_init main md5basic md5magic md5round \
	rot sha2chmaj sha2sig sha2transform sslbasic sslbasic1 update

SRCPATH = src
OBJPATH = obj

SRCFILE = $(addprefix $(SRCPATH)/, $(addsuffix .c, $(SRC)))
OBJFILE = $(addprefix $(OBJPATH)/, $(addsuffix .o, $(SRC)))

NAME = ft_ssl

all: $(NAME)

$(NAME): lib printf $(OBJFILE)
	$(CC) $(OBJFILE) -o $@ -Llibft -lft -Lft_printf -lftprintf

printf:
	make -C ft_printf

lib:
	make -C libft

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@ -Ift_printf/includes -Ilibft

clean:
	rm -rf obj
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean
	make -C ft_printf fclean

re: fclean all

.PHONY: clean fclean re all
