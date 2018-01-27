/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_hashtag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:30:49 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 23:08:01 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	lemin_hashtag(t_lemin *a, char *str, int *result)
{
	if (string_is_integer(str))
		*result = LEM_ANTS;
	else if (ft_strequ(str, "##start"))
		*result = LEM_START;
	else if (ft_strequ(str, "##end"))
		*result = LEM_END;
	else if ((str[0] == '#') && (str[1] == '#'))
		*result = LEM_COMMAND;
	else if ((str[0] == '#') && (str[1] != '#'))
		*result = LEM_COMMENT;
	if ((*result == LEM_COMMAND) && (ft_strequ(str, "##verbose")))
		a->verbose = 1;
	if ((*result == LEM_COMMAND) && (ft_strequ(str, "##ignore")))
		a->ignore = 1;
	if ((*result == LEM_COMMAND) && (ft_strequ(str, "##hidemap")))
		a->hide_map = 1;
	return ;
}
