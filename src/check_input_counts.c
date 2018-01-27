/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_counts.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:32:14 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:32:28 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	check_input_counts(t_lemin *a, int i)
{
	if (a->ic.room < 2)
		input_error("less than 2 rooms", a, i);
	if (a->ic.ants == 0)
		input_error("input is missing 'number of ants'", a, i);
	if (a->ic.ants > 1)
		input_error("multiple 'number of ants' lines", a, i);
	if (a->ic.start == 0)
		input_error("input is missing '##start' command", a, i);
	if (a->ic.start > 1)
		input_error("multiple '##start' commands", a, i);
	if (a->ic.end == 0)
		input_error("input is missing '##end' command", a, i);
	if (a->ic.end > 1)
		input_error("multiple '##end' commands", a, i);
	if (a->ic.link < 1)
		input_error("no links between rooms", a, i);
	return ;
}
