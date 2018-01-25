/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:35:11 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/24 23:47:43 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

