/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_is_enqueued.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:11:58 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:12:14 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		bfs_is_enqueued(t_room *queue, t_room *search)
{
	while (queue != NULL)
	{
		if (queue == search)
			return (1);
		queue = queue->child;
	}
	return (0);
}
