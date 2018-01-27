/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:31:19 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 01:58:31 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	get_input_type_three_elements(char **array, int *result)
{
	if ((string_is_integer(array[1])) && (string_is_integer(array[2])))
	{
		*result = LEM_ROOM;
		if ((array[0][0] == 'L') || (array[0][0] == '#'))
			*result = LEM_BADNAME;
	}
}

int		get_input_type(t_lemin *a, char *str)
{
	char	**array;
	char	**links;
	int		result;

	result = LEM_UNKNOWN;
	if (((array = ft_strsplit(str, ' ')) == NULL) || (array[0] == NULL))
		return (LEM_UNKNOWN);
	if ((array[0][0] == '#') && (array[0][1] != '#'))
		result = LEM_COMMENT;
	else if ((char_array_count_elements(array)) == 1)
	{
		lemin_hashtag(a, array[0], &result);
		if (result == LEM_UNKNOWN)
		{
			links = ft_strsplit(array[0], '-');
			if ((char_array_count_elements(links)) == 2)
				result = LEM_LINK;
			if (links != NULL)
				free_char_array(links);
		}
	}
	else if (char_array_count_elements(array) == 3)
		get_input_type_three_elements(array, &result);
	free_char_array(array);
	return (result);
}
