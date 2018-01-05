/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:54:37 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/04 20:03:10 by asarandi         ###   ########.fr       */
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
	struct s_room	**links;
}				t_room;

typedef struct	s_ant
{
	int	number;
	t_room	*room;
}				t_ant;

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
	a = create_room("0", 1, 0, LEM_START);	add_room(&antfarm, a);
	b = create_room("1", 5, 0, LEM_END);	add_room(&antfarm, b);
	c = create_room("2", 9, 0, 0);			add_room(&antfarm, c);
	d = create_room("3", 13, 0, 0);			add_room(&antfarm, d);

	add_link(&antfarm, "0", "2");	add_link(&antfarm, "2", "0");
	add_link(&antfarm, "2", "3");	add_link(&antfarm, "3", "2");
	add_link(&antfarm, "3", "1");	add_link(&antfarm, "1", "3");

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

int	main(void)
{
	get_input();
	ft_printf("lemmy lemmy lemmie lem\n\n");
	test1();
	return (0);
}
