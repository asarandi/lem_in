/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:33:34 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 16:32:32 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*bfs_find_special(t_room **antfarm, int special)
{
	int i = 0;
	while (antfarm[i] != NULL)
	{
		if (antfarm[i]->special == special)
			return (antfarm[i]);
		i++;
	}
	return (NULL);
}

void	bfs_enqueue(t_room *root, t_room *next)
{
	next->parent = root;
	next->depth = root->depth + 1;
	while (root->child != NULL)
	{
		root = root->child;
	}
	root->child = next;
	next->child = NULL;
}

void	bfs_dequeue(t_room **root)
{
	(*root) = (*root)->child;
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
		queue = queue->child;
	}
	return (0);
}


int	can_make_move(t_room *start, t_room *end)
{
	if (end->parent == NULL)
		return (1);
	while (end->parent != start)
		end = end->parent;
	if (end->has_ant == 1)
		return (0);
	else
		return (1);
}


t_room	*bfs_closest(t_lemin *a, t_room *queue, t_room *search)
{
	int		i;
	t_room	*start;
	start = queue;

	clear_room_flags(a);
	queue->depth = 0;
	while (queue != NULL)
	{
		queue->visited = 1;
		i = 0;
		while (queue->links[i] != NULL)
		{
			if (queue->links[i]->visited == 0)
			{
				if	(queue->links[i]->has_ant == 0)
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


void	bfs_display_shortest_path(t_lemin *a)
{
	int		i;
	t_room	*room;

	if (a->verbose)
	{
		i = 0;
		while (a->paths[i] != NULL)
		{
			ft_printf("{green}path #%d:{eoc}\n", i + 1);
			ft_printf("{green}%s {eoc} -> ", a->start->name);
			room = a->paths[i];
			while (room != NULL)
			{
				ft_printf("{green}%s{eoc} ", room->name);
				if (room != a-> end)
					ft_printf("-> ");
				room = room->next;
			}
			ft_printf("\n");
			i++;
		}
		ft_printf("\n");
	}
}


void	clear_all_rooms_of_ants(t_lemin *a)
{
	int	i;

	i = 0;
	while (a->rooms[i] != NULL)
	{
		a->rooms[i]->has_ant = 0;
		i++;
	}
	return ;
}



int	bfs_count_paths(t_lemin *a)
{
	int	i;

	i = 0;
	t_room	*solution;
	while (1)
	{
		solution = bfs_closest(a, a->start, a->end);
		if (solution == NULL)
			break ;
		if (solution->depth == 1)
			return (1);
		while (solution->parent != NULL)
		{
			if ((solution != a->end) && (solution != a->start))
				solution->has_ant = 1;
			solution = solution->parent;
		}
		i++;
	}
	clear_all_rooms_of_ants(a);
	return (i);
}


void	bfs_generate_paths(t_lemin *a)
{
	int	i;
	t_room	*solution;
	int count;

	count = bfs_count_paths(a);
	a->paths = ft_memalloc((count + 1) * sizeof(t_room *));
	i = 0;
	while (i < count)
	{
		solution = bfs_closest(a, a->start, a->end);
		while (solution->parent != NULL)
		{
			solution->parent->next = solution;
			if ((solution != a->end) && (solution != a->start))
				solution->has_ant = 1;
			solution = solution->parent;
		}
		a->paths[i] = solution->next;
		i++;
	}
	a->paths[i] = NULL;
	clear_all_rooms_of_ants(a);
}

void	bfs_is_map_valid(t_lemin *a)
{
	t_room	*end;
	t_room	*start;

	end = bfs_find_special(a->rooms, LEM_END);
	start = bfs_find_special(a->rooms, LEM_START);
	a->start = start;
	a->end = end;
	a->shortest = INT_MAX;
	end = bfs_closest(a, start, end);
	if (end == NULL)
	{
		if (a->verbose)
			ft_printf("{red}ERROR: invalid map, path from '##start' to '##end' not found{eoc}\n");
		else
			ft_printf("ERROR\n");
		destroy_antfarm(a);
		exit (0);
	}
}

t_room *bfs_next(t_lemin *a, t_room *start)
{
	t_room	*end;

	end = bfs_closest(a, start, a->end);
	if (end == NULL)
		return (NULL);
	while ((end->parent != start) && (end->parent != NULL))
		end = end->parent;
	

	return (end);
}


