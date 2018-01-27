/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_is_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:39:25 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:39:39 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
