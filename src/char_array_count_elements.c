/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_array_count_elements.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:46:55 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:47:12 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		char_array_count_elements(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return (i);
	while (array[i] != NULL)
		i++;
	return (i);
}
