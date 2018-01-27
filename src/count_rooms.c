/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:23:48 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:24:04 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		count_rooms(t_room **antfarm)
{
	int	i;

	if (antfarm == NULL)
		return (0);
	i = 0;
	while (antfarm[i] != NULL)
		i++;
	return (i);
}
