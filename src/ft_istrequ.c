/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istrequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:40:07 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:40:10 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	ft_istrequ(char *str1, char *str2)
{
	if (ft_istrcmp(str1, str2) == 0)
		return (1);
	return (0);
}
