/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_closest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:14:45 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 01:35:53 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*bfs_closest(t_lemin *a, t_room *queue, t_room *search)
{
	int		i;

	clear_room_flags(a);
	queue->depth = 0;
	while ((queue != NULL) && (queue->links != NULL))
	{
		queue->visited = 1;
		i = 0;
		while (queue->links[i] != NULL)
		{
			if (queue->links[i]->visited == 0)
			{
				if (queue->links[i]->has_ant == 0)
				{
					if (bfs_is_enqueued(queue, queue->links[i]) == 0)
						bfs_enqueue(queue, queue->links[i]);
					if (queue->links[i] == search)
						return (queue->links[i]);
				}
			}
			i++;
		}
		bfs_dequeue(&queue);
	}
	return (NULL);
}
