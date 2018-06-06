#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/02 13:58:30 by dlyubich          #+#    #+#              #
#    Updated: 2018/05/02 13:58:31 by dlyubich         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

BLUE = echo "\033[0;36m"
RED = echo "\033[0;34m"
GREEN = echo "\033[0;32m"
END = echo "\033[0m"

NAME = lem-in

FLAGS = -Wall -Wextra -Werror

SRC = checker.c \
			helper.c \
			helper2.c \
			main.c \
			matrix.c \
			parser.c \
			print.c \
			solution.c \
			errors.c \
			errors2.c
OBJ = $(SRC:.c=.o)
GCFLAGS = -I -I./libft/

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$$($(BLUE))LEM-IN : Sources compiling...$$($(END))"
	@make -C libft/
	-gcc $(FLAGS) $(GCFLAGS) -o $@ $(OBJ) $(LIBFT)
	@echo "$$($(GREEN))LEM-IN : compile with SUCCESS!$$($(END))"

$(OBJ_PATH_P)%.o: $(SRC_PATH_P)%.c
	-gcc $(FLAGS) $(GCFLAGS) -o $@ -c $<

libft/libft.a :
	@make -C libft

clean:
	@make -C libft/ clean
	rm -f $(OBJ)
	@echo "$$($(RED))Objects removed...$$($(END))"

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME)
	@echo "$$($(RED))lem-in binary removed...$$($(END))"

re: fclean all
