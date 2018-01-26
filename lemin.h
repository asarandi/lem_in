/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 00:43:31 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 02:43:12 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include <errno.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf/libftprintf.h"

#define	LEM_ANTS	1
#define	LEM_START	2
#define	LEM_END		3
#define	LEM_ROOM	4
#define	LEM_LINK	5
#define	LEM_COMMENT	6
#define	LEM_UNKNOWN	7
#define LEM_BADNAME 8

typedef struct	s_room
{
	char	**strings;
	char	*name;
	int		x;
	int		y;
	int		has_ant;
	int		ant;
	int		special;
	int		visited;
	int		depth;
	struct s_room	*parent;
	struct s_room	*child;
	struct s_room	*next;
	struct s_room	**links;
}				t_room;

typedef struct	s_ant
{
	int	number;
	int	is_done;
	t_room	*room;
}				t_ant;

struct	input_counts
{
	int	unknown;
	int	ants;
	int	start;
	int	end;
	int	comment;
	int	link;
	int	room;
};

typedef	struct	s_lemin
{
	struct	s_room			**paths;
	struct	s_room			**rooms;
	struct	s_ant			**ants;
	struct	input_counts	ic;
	char					*raw_input;
	int						raw_size;
	char					**string_array;
	int						lines;
	int						*input_type;
	int						verbose;
	int						shortest;
	int						number_of_ants;
	t_room					*start;
	t_room					*end;
}				t_lemin;


void	bfs_is_map_valid(t_lemin *a);
void	bfs_enqueue(t_room *root, t_room *next);
void	bfs_dequeue(t_room **root);
int		bfs_has_unvisited(t_room *room);
int		bfs_is_enqueued(t_room *queue, t_room *search);
t_room	*bfs_closest(t_lemin *a, t_room *queue, t_room *search);
t_room *bfs_next(t_lemin *a, t_room *start);

char	*stdin_read_eof(int *count);
int		bfs_has_unvisited(t_room *room);
int		bfs_is_enqueued(t_room *queue, t_room *search);
int		char_array_count_elements(char **array);
int		count_rooms(t_room **antfarm);
int		distance_to_end(t_room **antfarm, t_room *room);
int		ft_istrcmp(char *str1, char *str2);
int		get_input_type(char *str);
int		is_direct_link(t_room *room, t_room *search);
int		string_is_integer(char *str);
int		add_link(t_lemin *a, char *roomname, char *linkname);
int		add_room(t_room ***antfarm, t_room *room);
int		ant_can_move(t_ant *ant);
int		dfs_find_end(t_room *room, int *distance, int tmp, t_room **closest);
int		ft_istrequ(char *str1, char *str2);
int		main(int ac, char **av);
t_room	*create_room(char *name, int x, int y, int special);
t_room	*find_room(t_room **antfarm, char *roomname);
void	bfs_dequeue(t_room **root);
void	bfs_enqueue(t_room *root, t_room *next);
void	check_duplicate_room_names(t_lemin *a);
void	check_input_counts(t_lemin *a, int i);
void	clear_input_counts(t_lemin *a);
void	clear_room_flags(t_lemin *a);
void	compare_room_names(t_lemin *a, int i, int j);
void	create_room_array(t_lemin	*a);
void	create_room_links(t_lemin *a);
void	destroy_antfarm(t_lemin *a);
void	free_char_array(char **array);
void	get_input(t_lemin *a);
void	get_input_counts(t_lemin *a, int i);
void	input_error(char *message, t_lemin *a, int index);
void	print_antfarm(t_room **antfarm);
void	room_name_has_dashes(t_lemin *a, int index, char **a1, char **a2);
void	stdin_quit(char *membuf);
void	test1(void);




#endif
