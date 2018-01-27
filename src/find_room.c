/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:24:59 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 23:41:10 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*find_room(t_room **antfarm, char *roomname)
{
	int	i;

	if (antfarm == NULL)
		return (NULL);
	i = 0;
	while (antfarm[i] != NULL)
	{
		if (ft_strequ(antfarm[i]->name, roomname))
			return (antfarm[i]);
		i++;
	}
	return (NULL);
}
