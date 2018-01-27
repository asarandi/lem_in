/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:28:37 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:28:50 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_rooms(t_lemin *a)
{
	int	i;

	i = 0;
	while (a->rooms[i] != NULL)
	{
		if (a->rooms[i]->strings != NULL)
			free_char_array(a->rooms[i]->strings);
		free(a->rooms[i]->links);
		free(a->rooms[i]);
		a->rooms[i] = NULL;
		i++;
	}
	return ;
}
