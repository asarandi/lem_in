/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:24:25 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 01:35:34 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	add_room(t_room ***antfarm, t_room *room)
{
	int		count;
	int		i;
	t_room	**new_antfarm;

	count = count_rooms(*antfarm);
	new_antfarm = ft_memalloc((count + 2) * sizeof(t_room *));
	if (new_antfarm == NULL)
		return (-1);
	i = 0;
	while (i < count)
	{
		new_antfarm[i] = (*antfarm)[i];
		i++;
	}
	new_antfarm[i++] = room;
	new_antfarm[i] = NULL;
	if (*antfarm != NULL)
		free(*antfarm);
	(*antfarm) = new_antfarm;
	return (1);
}
