/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_has_duplicate_link.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:25:58 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 23:05:44 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
