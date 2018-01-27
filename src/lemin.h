/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 00:43:31 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 04:49:08 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <errno.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/libftprintf.h"

# define LEM_ANTS		1
# define LEM_START		2
# define LEM_END		3
# define LEM_ROOM		4
# define LEM_LINK		5
# define LEM_COMMENT	6
# define LEM_UNKNOWN	7
# define LEM_BADNAME	8
# define LEM_IGNORE		9
# define LEM_VERBOSE	10
# define LEM_HIDEMAP	11
# define LEM_COMMAND	12

typedef struct		s_room
{
	char			**strings;
	char			*name;
	int				x;
	int				y;
	int				has_ant;
	int				ant;
	int				special;
	int				visited;
	int				depth;
	struct s_room	*parent;
	struct s_room	*child;
	struct s_room	*next;
	struct s_room	**links;
}					t_room;

typedef struct		s_ant
{
	int				number;
	int				is_done;
	t_room			*room;
}					t_ant;

struct				s_ic
{
	int				unknown;
	int				ants;
	int				start;
	int				end;
	int				comment;
	int				link;
	int				room;
};

typedef struct		s_lemin
{
	struct s_room	**paths;
	struct s_room	**rooms;
	struct s_ant	**ants;
	struct s_ic		ic;
	char			*raw_input;
	int				raw_size;
	char			**string_array;
	int				lines;
	int				*input_type;
	int				verbose;
	int				ignore;
	int				hide_map;
	int				shortest;
	int				number_of_ants;
	t_room			*start;
	t_room			*end;
}					t_lemin;

char				*stdin_read_eof(int *count);
int					bfs_has_unvisited(t_room *room);
int					bfs_is_enqueued(t_room *queue, t_room *search);
int					char_array_count_elements(char **array);
int					count_rooms(t_room **antfarm);
int					distance_to_end(t_room **antfarm, t_room *room);
int					ft_istrcmp(char *str1, char *str2);
int					get_input_type(t_lemin *a, char *str);
int					string_is_integer(char *str);
int					add_link(t_lemin *a, char *linkname1, char *linkname2);
int					add_room(t_room ***antfarm, t_room *room);
int					bfs_count_paths(t_lemin *a);
int					can_make_move(t_room *start, t_room *end);
int					ft_istrequ(char *str1, char *str2);
int					stdin_is_empty(char *buffer, int *count);
int					main(int ac, char **av);
int					room_check_for_duplicates
						(t_lemin *a, t_room *room1, t_room *room2);
int					room_has_duplicate_link(t_room *room1, t_room *room2);
int					room_not_found(t_lemin *a, char *linkname);
t_room				*bfs_closest(t_lemin *a, t_room *queue, t_room *search);
t_room				*bfs_find_special(t_room **antfarm, int special);
t_room				*create_room(char *name, int x, int y, int special);
t_room				*find_room(t_room **antfarm, char *roomname);
t_room				*bfs_next(t_lemin *a, t_room *start);
void				bfs_dequeue(t_room **root);
void				bfs_display_shortest_path(t_lemin *a);
void				bfs_enqueue(t_room *root, t_room *next);
void				bfs_generate_paths(t_lemin *a);
void				bfs_is_map_valid(t_lemin *a);
void				check_duplicate_room_names(t_lemin *a);
void				check_input_counts(t_lemin *a, int i);
void				clear_all_rooms_of_ants(t_lemin *a);
void				clear_input_counts(t_lemin *a);
void				clear_room_flags(t_lemin *a);
void				compare_room_names(t_lemin *a, int i, int j);
void				create_ant_array(t_lemin *a);
void				create_link_array(t_lemin *a);
void				create_room_array(t_lemin	*a);
void				destroy_antfarm(t_lemin *a);
void				display_result(t_lemin *a);
void				display_usage(t_lemin *a);
void				fatal_error(t_lemin *a, char *msg);
void				free_ants(t_lemin *a);
void				free_char_array(char **array);
void				free_rooms(t_lemin *a);
void				get_input(t_lemin *a);
void				get_input_counts(t_lemin *a, int i);
void				input_error(char *message, t_lemin *a, int index);
void				lemin_hashtag(t_lemin *a, char *str, int *result);
void				room_name_has_dashes
						(t_lemin *a, int index, char **a1, char **a2);
void				stdin_quit(char *membuf);
void				cmd_line_opt(int ac, char **av, t_lemin *a);

#endif
