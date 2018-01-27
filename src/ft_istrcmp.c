/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:40:24 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 23:45:43 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_istrcmp_check_null(char *str1, char *str2)
{
	if ((str1 == NULL) && (str2 == NULL))
		return (0);
	if ((str1 == NULL) && (str2 != NULL))
		return (str2[0]);
	if ((str1 != NULL) && (str2 == NULL))
		return (str1[0]);
	return (1);
}

int		ft_istrcmp(char *str1, char *str2)
{
	char	a;
	char	b;
	int		i;

	i = ft_istrcmp_check_null(str1, str2);
	if (i != 1)
		return (i);
	i = 0;
	a = 0;
	b = 0;
	while ((str1[i]) || (str2[i]))
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
