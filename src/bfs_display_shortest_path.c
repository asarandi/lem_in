/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_display_shortest_path.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:15:17 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 01:26:50 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	bfs_display_shortest_path(t_lemin *a)
{
	int		i;
	t_room	*room;

	if (a->verbose)
	{
		i = 0;
		while (a->paths[i] != NULL)
		{
			ft_printf("{green2}path #%d:{eoc}\t", i + 1);
			ft_printf("{green}%s{eoc} -> ", a->start->name);
			room = a->paths[i];
			while (room != NULL)
			{
				ft_printf("{green}%s{eoc} ", room->name);
				if (room != a->end)
					ft_printf("-> ");
				room = room->next;
			}
			ft_printf("\n");
			i++;
		}
		ft_printf("\n");
	}
	return ;
}
