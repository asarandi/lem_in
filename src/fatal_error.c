/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:59:48 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:00:11 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	fatal_error(t_lemin *a, char *msg)
{
	if ((a->verbose) && (msg != NULL))
		ft_printf("{red}ERROR: %s{eoc}\n", msg);
	else
		ft_printf("ERROR\n");
	destroy_antfarm(a);
	exit(0);
}
