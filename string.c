/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:42:37 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/24 23:43:21 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_istrcmp(char *str1, char *str2)	//case insensitive compare
{
	char	a;
	char	b;
	int		i;

	if ((str1 == NULL) && (str2 == NULL))
		return (0);
	if ((str1 == NULL) && (str2 != NULL))
		return (str2[0]);
	if ((str1 != NULL) && (str2 == NULL))
		return (str1[0]);
	i = 0;
	while (str1[i])
	{
		a = str1[i];
		if ((a >= 'A') && (a <= 'Z'))
			a += 32;
		b = str2[i];
		if ((b >= 'A') && (b <= 'Z'))
			b += 32;
		if ((a == 0) || (b == 0) || (a - b != 0))
			break ;
		i++;
	}
	return (a - b);
}

int	ft_istrequ(char *str1, char *str2)
{
	if (ft_istrcmp(str1, str2) == 0)
		return (1);
	return (0);
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


