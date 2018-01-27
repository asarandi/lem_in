/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:35:20 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 23:05:26 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	stdin_quit(char *membuf)
{
	if (membuf != NULL)
		free(membuf);
	ft_printf("ERROR\n");
	perror(strerror(errno));
	exit(0);
}
