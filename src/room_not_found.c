/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_not_found.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:25:32 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:25:46 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	room_not_found(t_lemin *a, char *linkname)
{
	if (a->verbose)
	{
		ft_printf("{red}ERROR: error while creating links map{eoc}\n");
		ft_printf("{red}room name '%s' not found{eoc}\n", linkname);
	}
	else
		ft_printf("ERROR\n");
	return (-1);
}
