/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all_rooms_of_ants.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:15:47 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:16:03 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
