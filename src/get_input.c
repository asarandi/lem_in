/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:56:17 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 21:56:39 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	get_input(t_lemin *a)
{
	int i;

	a->raw_input = stdin_read_eof(&a->raw_size);
	if (a->raw_input == NULL)
		display_usage(a);
	a->string_array = ft_strsplit(a->raw_input, '\n');
	if (a->string_array == NULL)
		display_usage(a);
	a->lines = char_array_count_elements(a->string_array);
	a->input_type = ft_memalloc((a->lines + 1) * sizeof(int));
	i = 0;
	while (a->string_array[i] != NULL)
	{
		a->input_type[i] = get_input_type(a, a->string_array[i]);
		i++;
	}
	i = 0;
	clear_input_counts(a);
	get_input_counts(a, i);
	check_input_counts(a, i);
}
