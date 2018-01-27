/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate_room_names.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:58:04 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 21:58:29 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	check_duplicate_room_names(t_lemin *a)
{
	int i;
	int j;

	i = 0;
	while (i < a->lines - 1)
	{
		if (a->input_type[i] == LEM_ROOM)
		{
			j = i + 1;
			while (j < a->lines)
			{
				if (a->input_type[j] == LEM_ROOM)
				{
					compare_room_names(a, i, j);
				}
				j++;
			}
		}
		i++;
	}
	return ;
}
