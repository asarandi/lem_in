/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_check_for_duplicates.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:26:29 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 23:07:34 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	room_check_for_duplicates(t_lemin *a, t_room *room1, t_room *room2)
{
	if (room_has_duplicate_link(room1, room2) == 1)
	{
		if (a->verbose)
		{
			ft_printf("{red}ERROR: map error - duplicate links{eoc}\n");
			ft_printf("{red}room %s links to {eoc} ", room1->name);
			ft_printf("{red}room %s multiple times{eoc}\n", room2->name);
		}
		else
			ft_printf("ERROR\n");
		return (1);
	}
	return (0);
}
