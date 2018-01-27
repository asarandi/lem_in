/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_input_counts.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:32:41 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:32:59 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	clear_input_counts(t_lemin *a)
{
	a->ic.unknown = 0;
	a->ic.ants = 0;
	a->ic.start = 0;
	a->ic.end = 0;
	a->ic.comment = 0;
	a->ic.link = 0;
	a->ic.room = 0;
	return ;
}
