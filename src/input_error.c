/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:55:47 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 23:08:31 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	input_error(char *message, t_lemin *a, int index)
{
	if (a->verbose)
	{
		ft_printf("{white2}line %d: %s{eoc}\n",
				index + 1, a->string_array[index]);
		ft_printf("{red}ERROR: %s{eoc}\n", message);
	}
	else
		ft_printf("ERROR\n");
	free_char_array(a->string_array);
	free(a->input_type);
	free(a->raw_input);
	exit(0);
	return ;
}
