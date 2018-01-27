/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:02:38 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 01:24:10 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	cmd_line_opt(int ac, char **av, t_lemin *a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strequ(av[i], "-v"))
			a->verbose = 1;
		else if (ft_strequ(av[i], "-i"))
			a->ignore = 1;
		else if (ft_strequ(av[i], "-m"))
			a->hide_map = 1;
		else
			display_usage(a);
		i++;
	}
	return ;
}
