/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:33:34 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/24 23:51:13 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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


