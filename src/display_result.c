/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:01:05 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 04:21:20 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		path_available(t_lemin *a)
{
	int i;

	i = 0;
	while (a->paths[i] != NULL)
	{
		if (a->paths[i]->has_ant == 0)
			return (i);
		i++;
	}
	return (-1);
}

int		move_ant(t_lemin *a, int i)
{
	t_room	*current;

	current = a->ants[i]->room;
	if ((a->ants[i]->room == a->start) && (path_available(a) != -1))
		a->ants[i]->room = a->paths[path_available(a)];
	else if ((current != a->start) && (current->next->has_ant == 0))
		a->ants[i]->room = a->ants[i]->room->next;
	if (current != a->ants[i]->room)
	{
		current->has_ant = 0;
		a->ants[i]->room->has_ant = 1;
		a->end->has_ant = 0;
		ft_printf("L%d-%s ", i + 1, a->ants[i]->room->name);
		return (1);
	}
	ft_printf("\n");
	return (0);
}

void	display_result(t_lemin *a)
{
	int		i;
	int		f;

	while (1)
	{
		i = 0;
		f = 0;
		while (i < a->number_of_ants)
		{
			if (a->ants[i]->room != a->end)
			{
				f = 1;
				if (move_ant(a, i) == 0)
				{
					i = 0;
					continue ;
				}
			}
			i++;
		}
		if (f)
			ft_printf("\n");
		else
			break ;
	}
}
