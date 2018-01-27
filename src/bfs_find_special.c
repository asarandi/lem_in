/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_find_special.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:09:45 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 01:37:26 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*bfs_find_special(t_room **antfarm, int special)
{
	int	i;

	i = 0;
	while (antfarm[i] != NULL)
	{
		if (antfarm[i]->special == special)
			return (antfarm[i]);
		i++;
	}
	return (NULL);
}
