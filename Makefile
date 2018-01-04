# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/04 00:51:51 by asarandi          #+#    #+#              #
#    Updated: 2018/01/04 01:01:04 by asarandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
DFLAGS	= -g
SRC		= $(wildcard *.c)
OBJ		= $(SRC:%.c=%.o)
LIB		= -Llibft -lft -Lft_printf -lftprintf

all: $(NAME)

$(NAME):
	@make -C libft
	@make -C ft_printf
	$(info $(NAME):		compiling .o files)
	@$(CC) $(CFLAGS) -c $(SRC)
	$(info $(NAME):		building executable)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

debug: fclean
	@make debug -C libft
	@make debug -C ft_printf
	$(CC) $(DFLAGS) -c $(SRC)
	$(CC) $(DFLAGS) $(OBJ) $(LIB) -o debug

clean:
	@make clean -C libft
	@make clean -C ft_printf
	$(info $(NAME):		removing .o files)
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	$(info $(NAME):		removing $(NAME))
	@rm -rf $(NAME) debug

re: fclean all
