/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_name_has_dashes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:56:53 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 21:57:14 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	room_name_has_dashes(t_lemin *a, int index, char **a1, char **a2)
{
	if (a1 != NULL)
		free_char_array(a1);
	if (a2 != NULL)
		free_char_array(a2);
	input_error("dashes are not allowed in room names", a, index);
	return ;
}
