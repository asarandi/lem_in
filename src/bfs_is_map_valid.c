/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_is_map_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:17:21 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 01:38:57 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
		{
			ft_printf("{red}ERROR: invalid map, path from{eoc} ");
			ft_printf("{red}'##start' to '##end' not found{eoc}\n");
		}
		else
			ft_printf("ERROR\n");
		destroy_antfarm(a);
		exit(0);
	}
}
