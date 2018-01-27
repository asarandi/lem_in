/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_counts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:31:46 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 01:32:29 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	get_input_counts_other(t_lemin *a, int i)
{
	if (a->input_type[i] == LEM_COMMENT)
		a->ic.comment += 1;
	else if (a->input_type[i] == LEM_LINK)
		a->ic.link += 1;
	else if (a->input_type[i] == LEM_ROOM)
		a->ic.room += 1;
	else if (a->input_type[i] == LEM_ANTS)
		a->ic.ants += 1;
	return ;
}

void	get_input_counts(t_lemin *a, int i)
{
	while (i < a->lines)
	{
		if (a->input_type[i] == LEM_START)
		{
			a->ic.start += 1;
			if (a->input_type[i + 1] != LEM_ROOM)
				input_error("##start command must be followed by a room name",
						a, i + 1);
		}
		else if (a->input_type[i] == LEM_END)
		{
			a->ic.end += 1;
			if (a->input_type[i + 1] != LEM_ROOM)
				input_error("##end command must be followed by a room name",
						a, i + 1);
		}
		else if (a->input_type[i] == LEM_BADNAME)
			input_error("room names should not start with 'L' or '#'", a, i);
		else if (a->input_type[i] == LEM_UNKNOWN)
			input_error("could not parse this line", a, i);
		else
			get_input_counts_other(a, i);
		i++;
	}
}
