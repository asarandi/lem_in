/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:23:15 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:23:40 by asarandi         ###   ########.fr       */
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
