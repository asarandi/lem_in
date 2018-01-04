/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:54:37 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/04 01:07:50 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#define	LEM_ANTS	0
#define	LEM_START	1
#define	LEM_END		2
#define	LEM_ROOM	3
#define	LEM_LINK	4
#define	LEM_COMMENT	5
#define	LEM_UNKNOWN	6

void	free_char_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return ;
}

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

int		string_is_integer(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!is_digit(str[i]))
		{
			result = 0;
			break ;
		}
		result = 1;
		i++;
	}
	return (result);
}

int		get_input_type(char *str)
{
	char	**array;
	char	**links;
	int		result;

	result = LEM_UNKNOWN;
	if ((array = ft_strsplit(str, ' ')) == NULL)
		return (LEM_UNKNOWN);
	if ((char_array_count_elements(array)) == 1)
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
			result = LEM_ROOM;
	}
	free_char_array(array);
	return (result);
}

void	get_input(void)
{
	
}

int	main(void)
{
	get_input();
	ft_printf("lemmy lemmy lemmie lem\n");
	return (0);
}
