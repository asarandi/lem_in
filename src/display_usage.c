/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_usage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:02:04 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 01:33:49 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	display_usage(t_lemin *a)
{
	ft_printf("usage: ./lem-in [options] < [file]\n\n");
	ft_printf("options:\n");
	ft_printf("\t-m: do not display map when outputting result (##hidemap)\n");
	ft_printf("\t-i: do not quit when duplicate links found (##ignore)\n");
	ft_printf("\t-v: display paths found and ");
	ft_printf("verbose error messages (##verbose)\n");
	destroy_antfarm(a);
	exit(0);
}
