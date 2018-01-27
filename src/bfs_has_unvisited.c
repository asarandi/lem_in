/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_has_unvisited.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:11:25 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:11:41 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
