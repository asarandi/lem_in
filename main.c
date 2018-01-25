/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:54:37 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/24 23:51:25 by asarandi         ###   ########.fr       */
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


int		count_rooms(t_room **antfarm)
{
	int	i;

	if (antfarm == NULL)
		return (0);
	i = 0;
	while (antfarm[i] != NULL)
		i++;
	return (i);
}

void	clear_room_flags(t_room **antfarm)
{
	int	i;

	if (antfarm == NULL)
		return ;
	i = 0;
	while (antfarm[i] != NULL)
	{
		antfarm[i]->next = NULL;
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

t_room	*find_room(t_room **antfarm, char *roomname)
{
	int	i;

	if (antfarm == NULL)
		return (NULL);
	i = 0;
	while (antfarm[i] != NULL)
	{
		if (ft_strequ(antfarm[i]->name, roomname))
				return (antfarm[i]);
		i++;
	}
	return (NULL);
}


void	destroy_antfarm(t_room **antfarm)
{
	int	i;

	if (antfarm == NULL)
		return ;
	i = 0;
	while (antfarm[i] != NULL)
	{
		if (antfarm[i]->links != NULL)
			free(antfarm[i]->links);
		free(antfarm[i]);
		i++;
	}
	free(antfarm);
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
		ft_printf("is_start: [%d],\tis_end: [%d]\n", antfarm[i]->is_start, antfarm[i]->is_end);
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
	if (a->verbose == 1)
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

	add_link(&antfarm, "0", "2");	add_link(&antfarm, "2", "0");
	add_link(&antfarm, "0", "3");	add_link(&antfarm, "3", "0");
	add_link(&antfarm, "2", "1");	add_link(&antfarm, "1", "2");
	add_link(&antfarm, "3", "1");	add_link(&antfarm, "1", "3");
	add_link(&antfarm, "2", "3");	add_link(&antfarm, "3", "2");


//	int tmp = distance_to_end(antfarm, a);

//	t_room *next = bfs_next(antfarm, a);


	print_antfarm(antfarm);
	destroy_antfarm(antfarm);
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
		}
		i++;
	}
	a->rooms[j] = NULL;
}

void	create_room_links(t_lemin *a)
{
	int	i;
	char	**link;

	i = 0;
	while (i < a->lines)
	{
		if (a->input_type[i] == LEM_LINK)
		{
			link = ft_strsplit(a->string_array[i], ' ');


			free_char_array(link);

		}
	}
}

//
//implement room name validation for links	-DONE
//check for duplicate room names			-DONE
//check for duplicate links?				-maybe not
//throw error when room name has dashes?	-DONE
//
	

char	*e_noinput	= "error: no input file\n";
char	*e_badsize	= "errpr: bad file size\n";
char	*e_malloc	= "error: malloc failed\n";

int	main(int ac, char **av)
{
	t_lemin	*a;

	a = ft_memalloc(sizeof(t_lemin));
	if (a == NULL)
		return (ft_printf("ERROR\n"));
	if ((ac == 2) && (ft_strequ(av[1], "-v")))
		a->verbose = 1;
	get_input(a);
	check_duplicate_room_names(a);
	create_room_array(a);
	test1();
	return (0);
}
