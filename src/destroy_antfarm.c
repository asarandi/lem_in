/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_antfarm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:29:01 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:49:35 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	destroy_antfarm(t_lemin *a)
{
	if (a->ants != NULL)
		free_ants(a);
	if (a->rooms != NULL)
		free_rooms(a);
	if (a->paths != NULL)
		free(a->paths);
	free_char_array(a->string_array);
	free(a->input_type);
	free(a->raw_input);
	free(a);
	return ;
}
