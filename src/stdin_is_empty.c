/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_is_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:35:44 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:36:04 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <fcntl.h>

int	stdin_is_empty(char *buffer, int *count)
{
	ssize_t	r;

	r = 0;
	fcntl(0, F_SETFL, O_NONBLOCK);
	r = read(0, &buffer[0], 1);
	if (r == 1)
	{
		*count = 1;
		return (0);
	}
	free(buffer);
	return (1);
}
