# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/04 00:51:51 by asarandi          #+#    #+#              #
#    Updated: 2018/01/27 04:23:15 by asarandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Ofast
DFLAGS = -g
SFILES = add_link.c \
   add_room.c \
   bfs_closest.c \
   bfs_count_paths.c \
   bfs_dequeue.c \
   bfs_display_shortest_path.c \
   bfs_enqueue.c \
   bfs_find_special.c \
   bfs_generate_paths.c \
   bfs_has_unvisited.c \
   bfs_is_enqueued.c \
   bfs_is_map_valid.c \
   char_array_count_elements.c \
   check_duplicate_room_names.c \
   check_input_counts.c \
   clear_all_rooms_of_ants.c \
   clear_input_counts.c \
   clear_room_flags.c \
   cmd_line_opt.c \
   compare_room_names.c \
   count_rooms.c \
   create_ant_array.c \
   create_link_array.c \
   create_room.c \
   create_room_array.c \
   destroy_antfarm.c \
   display_result.c \
   display_usage.c \
   fatal_error.c \
   find_room.c \
   free_ants.c \
   free_char_array.c \
   free_rooms.c \
   ft_istrcmp.c \
   ft_istrequ.c \
   get_input.c \
   get_input_counts.c \
   get_input_type.c \
   input_error.c \
   lemin_hashtag.c \
   main.c \
   room_check_for_duplicates.c \
   room_has_duplicate_link.c \
   room_name_has_dashes.c \
   room_not_found.c \
   stdin_is_empty.c \
   stdin_quit.c \
   stdin_read_eof.c \
   string_is_integer.c

OFILES = $(patsubst %.c,%.o,$(SFILES))
SRC_DIR = src/
OBJ_DIR = obj/
SRC = $(addprefix $(SRC_DIR), $(SFILES))
OBJ = $(addprefix $(OBJ_DIR), $(OFILES))
LIB = -Llibft -lft -Lft_printf -lftprintf

all: $(NAME)

$(NAME): $(SRC)
	@make -C libft
	@make -C ft_printf
	$(info $(NAME):		compiling .o files)
	@$(CC) $(CFLAGS) -c $(SRC)
	@mkdir -p $(OBJ_DIR)
	@mv $(OFILES) $(OBJ_DIR)
	$(info $(NAME):		building executable)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

debug: fclean
	@make debug -C libft
	@make debug -C ft_printf
	$(CC) $(DFLAGS) -c $(SRC)
	@mkdir -p $(OBJ_DIR)
	@mv $(OFILES) $(OBJ_DIR)
	$(CC) $(DFLAGS) $(OBJ) $(LIB) -o debug

clean:
	@make clean -C libft
	@make clean -C ft_printf
	$(info $(NAME):		removing .o files)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	$(info $(NAME):		removing $(NAME))
	@rm -rf $(NAME) debug

re: fclean all
