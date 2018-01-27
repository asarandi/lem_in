/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_generate_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:16:53 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 01:26:25 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	bfs_generate_paths(t_lemin *a)
{
	int		i;
	t_room	*solution;
	int		count;

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
	return ;
}
