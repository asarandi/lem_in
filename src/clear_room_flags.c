/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_room_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:55:06 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 01:25:03 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	clear_room_flags(t_lemin *a)
{
	int		i;
	t_room	**antfarm;

	a->start->has_ant = 0;
	a->end->has_ant = 0;
	antfarm = a->rooms;
	if (antfarm == NULL)
		return ;
	i = 0;
	while (antfarm[i] != NULL)
	{
		antfarm[i]->parent = NULL;
		antfarm[i]->child = NULL;
		antfarm[i]->visited = 0;
		i++;
	}
	return ;
}
