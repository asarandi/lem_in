/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:26:57 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 01:35:08 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
	if (add_room(&room1->links, room2) == -1)
		return (-1);
	return (add_room(&room2->links, room1));
}
