/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:54:37 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 18:57:23 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	clear_room_flags(t_lemin *a)
{
	int	i;
	t_room **antfarm;

	a->start->has_ant = 0;
	a->end->has_ant = 0;

	antfarm = a->rooms;
	if (antfarm == NULL)
		return ;
	i = 0;
	while (antfarm[i] != NULL)
	{
		antfarm[i]->parent = NULL;
		antfarm[i]->child = NULL;
		antfarm[i]->visited = 0;
		i++;
	}
}

void	input_error(char *message, t_lemin *a, int index)
{
	if (a->verbose)
	{
		ft_printf("{white2}line %d: %s{eoc}\n", index + 1, a->string_array[index]);
		ft_printf("{red}ERROR: %s{eoc}\n", message);
	}
	else
		ft_printf("ERROR\n");
	free_char_array(a->string_array);
	free(a->input_type);	// array of ints for each line of raw input
	free(a->raw_input);
	exit(0);
	return ;
}

void	display_usage(t_lemin *a);

void	get_input(t_lemin *a)
{
	int i;

	a->raw_input = stdin_read_eof(&a->raw_size);
	if (a->raw_input == NULL)
		display_usage(a);
	a->string_array = ft_strsplit(a->raw_input, '\n');
	if (a->string_array == NULL)
		display_usage(a);
	a->lines = char_array_count_elements(a->string_array);
	a->input_type = ft_memalloc((a->lines + 1) * sizeof(int));
	i = 0;
	while (a->string_array[i] != NULL)
	{
		a->input_type[i] = get_input_type(a, a->string_array[i]);
		i++;
	}
	i = 0;
	clear_input_counts(a);
	get_input_counts(a, i);
	check_input_counts(a, i);
}

//////////////



void	room_name_has_dashes(t_lemin *a, int index, char **a1, char **a2)
{
	if (a1 != NULL)
		free_char_array(a1);
	if (a2 != NULL)
		free_char_array(a2);
	input_error("dashes are not allowed in room names", a, index);
	return ;
}


void	compare_room_names(t_lemin *a, int i, int j)
{
	char	**room1;
	char	**room2;
	int		result;

	result = 0;
	room1 = ft_strsplit(a->string_array[i], ' ');
	if (ft_strchr(room1[0], '-') != NULL)
		room_name_has_dashes(a, i, room1, NULL);
	room2 = ft_strsplit(a->string_array[j], ' ');
	if (ft_strchr(room2[0], '-') != NULL)
		room_name_has_dashes(a, j, room1, room2);
	if (ft_istrequ(room1[0], room2[0]) == 1)
	{
		result = 1;
		if (a->verbose)
			ft_printf("{white2}line %d: %s{eoc}\n", i, a->string_array[i]);
	}
	free_char_array(room1);
	free_char_array(room2);
	if (result == 1)
		input_error("duplicate room names found", a, j);
	return ;
}


void	check_duplicate_room_names(t_lemin *a)
{
	int i;
	int j;

	i = 0;
	while (i < a->lines - 1)
	{
		if (a->input_type[i] == LEM_ROOM)
		{
			j = i + 1;
			while (j < a->lines)
			{
				if (a->input_type[j] == LEM_ROOM)
				{
					compare_room_names(a, i, j);
				}
				j++;
			}
		}
		i++;
	}
}

void	create_room_array(t_lemin	*a)
{
	int	i;
	int	j;
	int	flag;
	char **room;

	a->rooms = ft_memalloc((a->ic.room + 1) * sizeof(t_room *));
	i = 0;
	j = 0;
	while (i < a->lines)
	{
		if (a->input_type[i] == LEM_ROOM)
		{
			flag = 0;
			if (i > 0)
			{
				if (a->input_type[i - 1] == LEM_START)
					flag = LEM_START;
				if (a->input_type[i - 1] == LEM_END)
					flag = LEM_END;
			}
			room = ft_strsplit(a->string_array[i], ' ');
			a->rooms[j] = create_room(room[0], ft_atoi(room[1]), ft_atoi(room[2]), flag);
			a->rooms[j]->strings = room;
			j++;
		}
		i++;
	}
	a->rooms[j] = NULL;
}

void	create_link_array(t_lemin *a)
{
	int		i;
	char	**link;
	int		flag;

	i = 0;
	while (i < a->lines)
	{
		if (a->input_type[i] == LEM_LINK)
		{
			flag = 0;
			link = ft_strsplit(a->string_array[i], '-');
			if (add_link(a, link[0], link[1]) == -1)
				flag = 1;
			free_char_array(link);
			if (flag == 1)
			{
				destroy_antfarm(a);
				exit(0);
			}

		}
		i++;
	}
}

void	fatal_error(t_lemin *a, char *msg)
{
	if ((a->verbose) && (msg != NULL))
		ft_printf("{red}ERROR: %s{eoc}\n", msg);
	else
		ft_printf("ERROR\n");
	destroy_antfarm(a);
	exit(0);
}

void	create_ant_array(t_lemin *a)
{
	int		i;

	i = 0;
	a->number_of_ants = 0;
	while (i < a->lines)
	{
		if (a->input_type[i] == LEM_ANTS)
		{
			a->number_of_ants = ft_atoi(a->string_array[i]);
			break ;
		}
		i++;
	}
	if ((a->number_of_ants < 1) || (a->number_of_ants >= INT_MAX))
		fatal_error(a, "map error - bad number of ants");
	a->ants = ft_memalloc((a->number_of_ants + 1) * sizeof(t_ant *));
	if (a->ants == NULL)
		fatal_error(a, "malloc failed");
	i = 0;
	while (i < a->number_of_ants)
	{
		a->ants[i] = ft_memalloc(sizeof(t_ant));
		if (a->ants[i] == NULL)
			fatal_error(a, "malloc failed");
		a->ants[i]->room = a->start;
		i++;
	}
	return ;
}

void	display_result(t_lemin *a)
{
	int		i;
	int		j;
	int		f;

	while (1)
	{
		j = 0;
		i = 0;
		f = 0;
		while (a->ants[i] != NULL)
		{
			a->end->has_ant = 0;

			if (a->ants[i]->room != a->end)
			{
				f = 1;
				if (a->ants[i]->room == a->start)
				{
					while (a->paths[j]->has_ant == 1)
						j++;
					if (a->paths[j] == NULL)
						break ;
					a->ants[i]->room = a->paths[j++];
					if (a->ants[i]->room != a->end)
						a->ants[i]->room->has_ant = 1;
					ft_printf("L%d-%s ", i + 1, a->ants[i]->room->name);
					if (a->paths[j] == NULL)
					{
						i = 0;
						j = 0;
						ft_printf("\n");
						continue ;
					}

				}
				else
				{
					if (a->ants[i]->room->next->has_ant == 0)
					{
						a->ants[i]->room->has_ant = 0;
						a->ants[i]->room = a->ants[i]->room->next;
						if (a->ants[i]->room != a->end)
							a->ants[i]->room->has_ant = 1;
						ft_printf("L%d-%s ", i + 1, a->ants[i]->room->name);
					}
				}
			}
			i++;
		}
		if (f)
			ft_printf("\n");
		else
			break ;
	}

}

void	bfs_display_shortest_path(t_lemin *a);
void	bfs_is_map_valid(t_lemin *a);
void	bfs_generate_paths(t_lemin *a);


void	display_usage(t_lemin *a)
{
	ft_printf("usage: ./lem-in [options] < [file]\n\n");
	ft_printf("options:\n");
	ft_printf("\t-m: do not display map when outputting result (##hidemap)\n");
	ft_printf("\t-i: do not quit when duplicate links found (##ignore)\n");
	ft_printf("\t-v: display paths found and verbose error messages (##verbose)\n");
/*
** 	ft_printf("\t-h: show this help message and quit\n");
*/
	destroy_antfarm(a);
	exit (0);
}


void cmd_line_opt(int ac, char **av, t_lemin *a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strequ(av[i], "-v"))
			a->verbose = 1;
		else if  (ft_strequ(av[i], "-i"))
			a->ignore = 1;
		else if (ft_strequ(av[i], "-m"))
			a->hide_map = 1;
		else
			display_usage(a);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_lemin	*a;

	a = ft_memalloc(sizeof(t_lemin));
	if (a == NULL)
		return (ft_printf("ERROR\n"));
	cmd_line_opt(ac, av, a);
	get_input(a);
	check_duplicate_room_names(a);
	create_room_array(a);
	create_link_array(a);
	bfs_is_map_valid(a);
	create_ant_array(a);
	bfs_is_map_valid(a);
	if (a->hide_map == 0)
		ft_printf("%s\n", a->raw_input);
	bfs_generate_paths(a);
	bfs_display_shortest_path(a);
	display_result(a);
	destroy_antfarm(a);
	return (0);
}
