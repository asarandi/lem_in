/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:54:37 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/22 22:57:55 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#define	LEM_ANTS	0
#define	LEM_START	1
#define	LEM_END		2
#define	LEM_ROOM	3
#define	LEM_LINK	4
#define	LEM_COMMENT	5
#define	LEM_UNKNOWN	6

typedef struct	s_room
{
	char	*name;
	int		x;
	int		y;
	int		has_ant;
	int		ant;
	int		is_start;
	int		is_end;
	int		visited;
	struct s_room	*next;
	struct s_room	**links;
}				t_room;

typedef struct	s_ant
{
	int	number;
	int	is_done;
	t_room	*room;
}				t_ant;

static int	g_verbose;

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

t_room	*create_room(char *name, int x, int y, int special)
{
	t_room	*room;

	if ((room = ft_memalloc(sizeof(t_room))) == NULL)
		return (NULL);
	room->name = name;
	room->x = x;
	room->y = y;
	room->has_ant = 0;
	room->ant = 0;
	room->is_start = 0;
	room->is_end = 0;
	room->visited = 0;
	room->next = NULL;
	if (special == LEM_START)
		room->is_start = 1;
	if (special == LEM_END)
		room->is_end = 1;
	room->links = NULL;
	return (room);
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


void	bfs_enqueue(t_room *root, t_room *next)
{
	while (root->next != NULL)
	{
		root = root->next;
	}
	root->next = next;
	next->next = NULL;
}

void	bfs_dequeue(t_room **root)
{
	(*root) = (*root)->next;
}

int		bfs_has_unvisited(t_room *room)
{
	int	i;

	i = 0;
	while (room->links[i] != NULL)
	{
		if (room->links[i]->visited == 0)
			return (1);
		i++;
	}
	return (0);
}

int		bfs_is_enqueued(t_room *queue, t_room *search)
{
	while (queue != NULL)
	{
		if (queue == search)
			return (1);
		queue = queue->next;
	}
	return (0);
}

t_room	*bfs_closest(t_room **antfarm, t_room *queue, t_room *search)
{
	int		i;

	clear_room_flags(antfarm);
	while (queue != NULL)
	{
		queue->visited = 1;
		i = 0;
		while (queue->links[i] != NULL)
		{
			if (queue->links[i] == search)
				return (queue);
			if (queue->links[i]->visited == 0)
			{
				if (bfs_is_enqueued(queue, queue->links[i]) == 0)
					bfs_enqueue(queue, queue->links[i]);
			}
			i++;
		}
		bfs_dequeue(&queue);
	}
	return (NULL);
}


t_room	*find_end_room(t_room **antfarm)
{
	int i = 0;
	while (antfarm[i] != NULL)
	{
		if (antfarm[i]->is_end == 1)
			return (antfarm[i]);
		i++;
	}
	return (NULL);
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

t_room *bfs_next(t_room **antfarm, t_room *start)
{
	t_room	*destination;

	destination = find_end_room(antfarm);
	while (is_direct_link(start, destination) == 0)
	{
		destination = bfs_closest(antfarm, start, destination);
	}
	return (destination);
}



int	dfs_find_end(t_room *room, int *distance, int tmp, t_room **closest)
{
	int		i;
	int		temp;

	if (room->is_end == 1)
	{
		if (tmp < *distance)
			*distance = tmp;
		return (1);
	}

	i = 0;
	temp = 0;
	room->visited = 1;
	while (room->links[i] != NULL)
	{

		if (room->links[i]->visited == 0)
		{
			if ((dfs_find_end(room->links[i], distance, ++tmp, closest)) == 1)
			{	
				(*closest) = room->links[i];
				temp = 1;
			}
		}
		i++;
	}
	return (temp);
}

int		distance_to_end(t_room **antfarm, t_room *room)
{
	int	distance;
	t_room	*closest;

	closest = NULL;
	clear_room_flags(antfarm);
	distance = count_rooms(antfarm);
	if ((dfs_find_end(room, &distance, 0, &closest)) == 1)
	{
		ft_printf("distance to end: [%d], room: [%s] \n", distance, closest->name);
		return (distance);
	}
	else
		return (-1);
}

int	add_room(t_room ***antfarm, t_room *room)
{
	int	count;
	int	i;
	t_room	**new_antfarm;

	count = count_rooms(*antfarm);
	new_antfarm = ft_memalloc((count + 2) * sizeof(t_room *));
	if (new_antfarm == NULL)
		return (0);
	i = 0;
	while (i < count)
	{
		new_antfarm[i] = (*antfarm)[i];
		i++;
	}
	new_antfarm[i++] = room;
	new_antfarm[i] = NULL;
	if (*antfarm != NULL)
		free(*antfarm);
	(*antfarm) = new_antfarm;
	return (1);
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

int	add_link(t_room ***antfarm, char *roomname, char *linkname)
{
	t_room	*room1;
	t_room	*room2;

	room1 = find_room(*antfarm, roomname);
	room2 = find_room(*antfarm, linkname);
	if ((room1 == NULL) || (room2 == NULL))
		return (-1);

	return (add_room(&room1->links, room2));
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


	int tmp = distance_to_end(antfarm, a);

	t_room *next = bfs_next(antfarm, a);


	print_antfarm(antfarm);
	destroy_antfarm(antfarm);
}



void	free_char_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return ;
}

int		char_array_count_elements(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return (i);
	while (array[i] != NULL)
		i++;
	return (i);
}

int		string_is_integer(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!is_digit(str[i]))
		{
			result = 0;
			break ;
		}
		result = 1;
		i++;
	}
	return (result);
}

int		get_input_type(char *str)
{
	char	**array;
	char	**links;
	int		result;

	result = LEM_UNKNOWN;
	if ((array = ft_strsplit(str, ' ')) == NULL)
		return (LEM_UNKNOWN);
	if ((char_array_count_elements(array)) == 1)
	{
		if (string_is_integer(array[0]))
			result = LEM_ANTS;
		else if (ft_strequ(array[0], "##start"))
			result = LEM_START;
		else if (ft_strequ(array[0], "##end"))
			result = LEM_END;
		else if ((array[0][0] == '#') && (array[0][1] != '#'))
			result = LEM_COMMENT;
		else
		{
			links = ft_strsplit(array[0], '-');
			if ((char_array_count_elements(links)) == 2)
				result = LEM_LINK;
			if (links != NULL)
				free_char_array(links);
		}
	}
	else if (char_array_count_elements(array) == 3)
	{
		if ((string_is_integer(array[1])) && (string_is_integer(array[2])))
			result = LEM_ROOM;
	}
	free_char_array(array);
	return (result);
}

void	get_input(void)
{
	
}

char	*e_noinput	= "error: no input file\n";
char	*e_badsize	= "errpr: bad file size\n";
char	*e_malloc	= "error: malloc failed\n";

int	main(int ac, char **av)
{
	if ((ac == 2) && (ft_strequ(av[1], "-v")))
		g_verbose = 1;
	get_input();
	test1();
	return (0);
}
