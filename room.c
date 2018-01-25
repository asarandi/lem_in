/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:36:37 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/24 23:38:28 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

