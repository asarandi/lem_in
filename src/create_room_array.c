/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:58:42 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 02:02:24 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		create_room_array_flag(t_lemin *a, int i)
{
	int	flag;

	flag = 0;
	if (i > 0)
	{
		if (a->input_type[i - 1] == LEM_START)
			flag = LEM_START;
		if (a->input_type[i - 1] == LEM_END)
			flag = LEM_END;
	}
	return (flag);
}

void	create_room_array(t_lemin *a)
{
	int		i;
	int		j;
	int		flag;
	char	**room;

	a->rooms = ft_memalloc((a->ic.room + 1) * sizeof(t_room *));
	i = 0;
	j = 0;
	while (i < a->lines)
	{
		if (a->input_type[i] == LEM_ROOM)
		{
			flag = create_room_array_flag(a, i);
			room = ft_strsplit(a->string_array[i], ' ');
			a->rooms[j] = create_room(room[0],
					ft_atoi(room[1]), ft_atoi(room[2]), flag);
			a->rooms[j]->strings = room;
			j++;
		}
		i++;
	}
	a->rooms[j] = NULL;
	return ;
}
