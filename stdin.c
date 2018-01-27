/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:40:15 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 18:10:23 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <fcntl.h>

void	stdin_quit(char *membuf)
{
	if (membuf != NULL)
		free(membuf);
	ft_printf("ERROR\n");
	perror(strerror(errno));
	exit (0);
}

int	is_stdin_empty(char *buffer, int *count)
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

char	*stdin_read_eof(int *count)
{
	char	*buffer;
	char	*newbuf;
	ssize_t			r;

	if ((buffer = ft_memalloc(1024)) == NULL)
		stdin_quit(NULL);
	if (is_stdin_empty(buffer, count))
		return (NULL);
	r = 1;
	while (r != 0)
	{
		if ((r = read(0, &buffer[*count], 1024 - (*count % 1024))) == -1)
			stdin_quit(buffer);
		*count += r;
		if ((*count) && (*count % 1024 == 0) && (r != 0))
		{
			if ((newbuf = ft_memalloc(*count + 1024)) == NULL)
				stdin_quit(buffer);
			ft_memcpy(newbuf, buffer, *count);
			free(buffer);
			buffer = newbuf;
			r = 1;
		}
	}
	return (buffer);
}
