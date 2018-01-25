/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:41:20 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/24 23:42:20 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_input_type(char *str)
{
	char	**array;
	char	**links;
	int		result;

	result = LEM_UNKNOWN;
	if ((array = ft_strsplit(str, ' ')) == NULL)
		return (LEM_UNKNOWN);


	if ((array[0][0] == '#') && (array[0][1] != '#'))
	{
			result = LEM_COMMENT;
	}
	else if ((char_array_count_elements(array)) == 1)
	{
		if (string_is_integer(array[0]))
			result = LEM_ANTS;
		else if (ft_strequ(array[0], "##start"))
			result = LEM_START;
		else if (ft_strequ(array[0], "##end"))
			result = LEM_END;
		else if ((array[0][0] == '#') && (array[0][1] != '#'))
			result = LEM_COMMENT;
		else
		{
			links = ft_strsplit(array[0], '-');
			if ((char_array_count_elements(links)) == 2)
				result = LEM_LINK;
			if (links != NULL)
				free_char_array(links);
		}
	}
	else if (char_array_count_elements(array) == 3)
	{
		if ((string_is_integer(array[1])) && (string_is_integer(array[2])))
		{
			result = LEM_ROOM;
			if ((array[0][0] == 'L') || (array[0][0] == '#'))
				result = LEM_BADNAME;// room names should never start with 'L' or '#'
		}
	}
	free_char_array(array);
	return (result);
}

void	get_input_counts(t_lemin *a, int i)
{
	while (i < a->lines)
	{
		if (a->input_type[i] == LEM_ANTS)
			a->ic.ants += 1;
		else if (a->input_type[i] == LEM_START)
		{
			a->ic.start += 1;
			if (a->input_type[i + 1] != LEM_ROOM)
				input_error("##start command must be followed by a room name", a, i + 1);
		}
		else if (a->input_type[i] == LEM_END)
		{
			a->ic.end += 1;
			if (a->input_type[i + 1] != LEM_ROOM)
				input_error("##end command must be followed by a room name", a, i + 1);
		}
		else if (a->input_type[i] == LEM_COMMENT)
			a->ic.comment += 1;
		else if (a->input_type[i] == LEM_LINK)
			a->ic.link += 1;
		else if (a->input_type[i] == LEM_ROOM)
			a->ic.room += 1;
		else if (a->input_type[i] == LEM_BADNAME)
			input_error("room names should not start with 'L' or '#'", a, i);
		else
			input_error("could not parse this line", a, i);
		i++;
	}
}

void	check_input_counts(t_lemin *a, int i)
{
	if (a->ic.room < 2)
		input_error("less than 2 rooms", a, i);
	if (a->ic.ants == 0)
		input_error("input is missing 'number of ants'", a, i);
	if (a->ic.ants > 1)
		input_error("multiple 'number of ants' lines", a, i);
	if (a->ic.start == 0)
		input_error("input is missing '##start' command", a, i);
	if (a->ic.start > 1)
		input_error("multiple '##start' commands", a, i);
	if (a->ic.end == 0)
		input_error("input is missing '##end' command", a, i);
	if (a->ic.end > 1)
		input_error("multiple '##end' commands", a, i);
	if (a->ic.link < 1)
		input_error("no links between rooms", a, i);
	return ;
}

void	clear_input_counts(t_lemin *a)
{
	a->ic.unknown = 0;
	a->ic.ants = 0;
	a->ic.start = 0;
	a->ic.end = 0;
	a->ic.comment = 0;
	a->ic.link = 0;
	a->ic.room = 0;
}

