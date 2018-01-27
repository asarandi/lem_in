/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:54:37 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 16:28:13 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"


int	ant_can_move(t_ant *ant)
{
	int	i;
	t_room	**links;

	if (ant == NULL)
		return (-1);
	if (ant->room == NULL)
		return (-2);
	if (ant->room->links == NULL)
		return (-3);
	if (ant->room->links[0] == NULL)
		return (-4);
	links = ant->room->links;
	i = 0;
	while (links[i] != NULL)
	{
		if (links[i]->has_ant == 0)
			return (1);
		i++;
	}
	return (0);
}


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

int		is_direct_link(t_room *room, t_room *search)
{
	int	i;

	i = 0;
	while (room->links[i] != NULL)
	{
		if (room->links[i] == search)
			return (1);
		i++;
	}
	return (0);
}


void	print_antfarm(t_room **antfarm)
{
	int i;
	int	j;
	t_room	**links;

	if (antfarm == NULL)
		return ;
	i = 0;
	while (antfarm[i] != NULL)
	{
		ft_printf("name: [%s],\tx: [%d], \ty: [%d]\t", antfarm[i]->name, antfarm[i]->x, antfarm[i]->y);
		ft_printf("has_ant: [%d],\tant: [%d],\t", antfarm[i]->has_ant, antfarm[i]->ant);
		ft_printf("\tspecial: [%d]\n", antfarm[i]->special);
		links = antfarm[i]->links;
		if (links != NULL)
		{
			j = 0;
			while (links[j] != NULL)
			{
				ft_printf("\tlink %d:\t [%s]\n", j, links[j]->name);
				j++;
			}
			ft_printf("\n");
		}


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
	free_char_array(a->string_array);	//array of char ** from str_split
	free(a->input_type);	// array of ints for each line of raw input
	free(a->raw_input);
	exit(0);
	return ;
}



void	get_input(t_lemin *a)
{
	int i;

	a->raw_input = stdin_read_eof(&a->raw_size);
	a->string_array = ft_strsplit(a->raw_input, '\n');
	a->lines = char_array_count_elements(a->string_array);
	a->input_type = ft_memalloc((a->lines + 1) * sizeof(int));

	i = 0;
	while (a->string_array[i] != NULL)
	{
		a->input_type[i] = get_input_type(a->string_array[i]);
		i++;
	}
	i = 0;
	clear_input_counts(a);	// use ft_memalloc because it sets memory to 0
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


void	test1(void)
{
	t_room	*a;
	t_room	*b;
	t_room	*c;
	t_room	*d;
	t_room	**antfarm;

	antfarm = NULL;
//pdf example 2
	a = create_room("0", 1, 2, LEM_START);	add_room(&antfarm, a);
	b = create_room("1", 9, 2, LEM_END);	add_room(&antfarm, b);
	c = create_room("2", 5, 0, 0);			add_room(&antfarm, c);
	d = create_room("3", 5, 4, 0);			add_room(&antfarm, d);

//	add_link(&antfarm, "0", "2");	add_link(&antfarm, "2", "0");
//	add_link(&antfarm, "0", "3");	add_link(&antfarm, "3", "0");
//	add_link(&antfarm, "2", "1");	add_link(&antfarm, "1", "2");
//	add_link(&antfarm, "3", "1");	add_link(&antfarm, "1", "3");
//	add_link(&antfarm, "2", "3");	add_link(&antfarm, "3", "2");


//	int tmp = distance_to_end(antfarm, a);

//	t_room *next = bfs_next(antfarm, a);


	print_antfarm(antfarm);
//	destroy_antfarm(antfarm);
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



void	play(t_lemin *a)
{
	int		i;
	int		flag;
	t_room	*next;

	while (1)
	{
		i = 0;
		flag = 0;
		while (a->ants[i] != NULL)
		{
			if (a->ants[i]->room != a->end)
			{
				flag = 1;

				next = bfs_next(a, a->ants[i]->room);
				if ((next != NULL) && ((next->has_ant == 0) || next == a->end))
				{
					a->ants[i]->room->has_ant = 0;
					ft_printf("L%d-%s ", i + 1, next->name);
					a->ants[i]->room = next;
					a->ants[i]->room->has_ant = 1;
				}
//				else
//				{
//					ft_printf("for ant %d .. next is NULL\n", i + 1);
//					flag = 1;
//					break ;
//				}
			}
			i++;
		}
		ft_printf("\n");
		if (flag == 0)
			break ;
	}
}





void	play2(t_lemin *a)
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
		ft_printf("\n");
		if (f == 0)
			break ;
	}

}





//
//implement room name validation for links	-DONE
//check for duplicate room names			-DONE
//check for duplicate links?				-DONE
//throw error when room name has dashes?	-DONE
//

void	bfs_display_shortest_path(t_lemin *a);
void	bfs_is_map_valid(t_lemin *a);
void	bfs_generate_paths(t_lemin *a);

char	*e_noinput	= "error: no input file\n";
char	*e_badsize	= "errpr: bad file size\n";
char	*e_malloc	= "error: malloc failed\n";


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
//	ft_printf("%s\n", a->raw_input);
	bfs_is_map_valid(a);
	bfs_generate_paths(a);
	bfs_display_shortest_path(a);

	play2(a);
	

	destroy_antfarm(a);

	return (0);
}
