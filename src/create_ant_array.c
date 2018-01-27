/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ant_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:00:33 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 01:46:43 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	create_ant_array_default_room(t_lemin *a)
{
	int	i;

	i = 0;
	while (i < a->number_of_ants)
	{
		a->ants[i] = ft_memalloc(sizeof(t_ant));
		if (a->ants[i] == NULL)
			fatal_error(a, "malloc failed");
		a->ants[i]->room = a->start;
		i++;
	}
}

void	create_ant_array(t_lemin *a)
{
	int		i;

	i = 0;
	a->number_of_ants = 0;
	while (i < a->lines)
	{
		if (a->input_type[i] == LEM_ANTS)
		{
			a->number_of_ants = ft_atoi(a->string_array[i]);
			break ;
		}
		i++;
	}
	if ((a->number_of_ants < 1) || (a->number_of_ants >= INT_MAX))
		fatal_error(a, "map error - bad number of ants");
	a->ants = ft_memalloc((a->number_of_ants + 1) * sizeof(t_ant *));
	if (a->ants == NULL)
		fatal_error(a, "malloc failed");
	create_ant_array_default_room(a);
	return ;
}
