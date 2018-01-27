/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_room_names.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:57:26 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 21:57:48 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	compare_room_names(t_lemin *a, int i, int j)
{
	char	**room1;
	char	**room2;
	int		result;

	result = 0;
	room1 = ft_strsplit(a->string_array[i], ' ');
	if (ft_strchr(room1[0], '-') != NULL)
		room_name_has_dashes(a, i, room1, NULL);
	room2 = ft_strsplit(a->string_array[j], ' ');
	if (ft_strchr(room2[0], '-') != NULL)
		room_name_has_dashes(a, j, room1, room2);
	if (ft_istrequ(room1[0], room2[0]) == 1)
	{
		result = 1;
		if (a->verbose)
			ft_printf("{white2}line %d: %s{eoc}\n", i, a->string_array[i]);
	}
	free_char_array(room1);
	free_char_array(room2);
	if (result == 1)
		input_error("duplicate room names found", a, j);
	return ;
}
