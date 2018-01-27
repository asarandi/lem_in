/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:36:37 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 17:11:04 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*create_room(char *name, int x, int y, int special)
{
	t_room	*room;

	if ((room = ft_memalloc(sizeof(t_room))) == NULL)
		return (NULL);
	room->strings = NULL;
	room->name = name;
	room->x = x;
	room->y = y;
	room->has_ant = 0;
	room->ant = 0;
	room->visited = 0;
	room->child = NULL;
	room->parent = NULL;
	room->special = special;
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
		return (-1);
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



int	room_not_found(t_lemin *a, char *linkname)
{
	if (a->verbose)
	{
		ft_printf("{red}ERROR: error while creating links map{eoc}\n");
		ft_printf("{red}room name '%s' not found{eoc}\n", linkname);
	}
	else
		ft_printf("ERROR\n");
	return (-1);
}


int	room_has_duplicate_link(t_room *room1, t_room *room2) 
{
	int			i;

	if ((room1->links == NULL) || (room2->links == NULL))
		return (0);
	i = 0;
	while (room1->links[i] != NULL)
	{
		if (room1->links[i] == room2)
			return (1);
		i++;
	}
	i = 0;
	while (room2->links[i] != NULL)
	{
		if (room2->links[i] == room1)
			return (1);
		i++;
	}
	return (0);
}

int	room_check_for_duplicates(t_lemin *a, t_room *room1, t_room *room2)
{
	if (room_has_duplicate_link(room1, room2) == 1)
	{
		if (a->verbose)
		{
			ft_printf("{red}ERROR: map error - duplicate links{eoc}\n");
			ft_printf("{red}room %s links to room %s multiple times{eoc}\n", room1->name, room2->name);
		}
		else
			ft_printf("ERROR\n");

		return (1);

	}
	return (0);
}

int	add_link(t_lemin *a, char *linkname1, char *linkname2)
{
	t_room	*room1;
	t_room	*room2;
	int		is_dupe;

	room1 = find_room(a->rooms, linkname1);
	if (room1 == NULL)
		return (room_not_found(a, linkname1));
	room2 = find_room(a->rooms, linkname2);
	if (room2 == NULL)
		return (room_not_found(a, linkname2));
	is_dupe = room_check_for_duplicates(a, room1, room2);
	if (is_dupe == 1)
		return (a->ignore == 1 ? 1 : -1);
	if (add_room(&room1->links, room2) == -1)	//add room2 to the list of links of room1
		return (-1);
	return (add_room(&room2->links, room1));	//add room1 to the list of links for room2
}



void	free_ants(t_lemin *a)
{
	int	i;

	i = 0;
	while (a->ants[i] != NULL)
	{
		free(a->ants[i]);
		i++;
	}
	return ;
}

void	free_rooms(t_lemin *a)
{
	int	i;

	i = 0;
	while (a->rooms[i] != NULL)
	{
		if (a->rooms[i]->strings != NULL)
			free_char_array(a->rooms[i]->strings);
		free(a->rooms[i]->links);
		free(a->rooms[i]);
		a->rooms[i] = NULL;
		i++;
	}
	return ;
}

void	destroy_antfarm(t_lemin *a)
{
	if (a->ants != NULL)
		free_ants(a);
	if (a->rooms != NULL)
		free_rooms(a);
	if (a->paths != NULL)
		free(a->paths);
	free_char_array(a->string_array);	//array of char ** from str_split
	free(a->input_type);	// array of ints for each line of raw input
	free(a->raw_input);
	free(a);
}
