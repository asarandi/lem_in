/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_count_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:16:22 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 01:36:38 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	bfs_count_paths(t_lemin *a)
{
	int		i;
	t_room	*solution;

	i = 0;
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
