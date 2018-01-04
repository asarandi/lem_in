/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 00:43:31 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/04 01:10:56 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include "libft/libft.h"
#include "ft_printf/libftprintf.h"

# define BUFF_SIZE 1

typedef	struct		s_gnl
{
	void			*mem;
	size_t			size;
	int				fd;
	int				eof;
	struct s_gnl	*prev;
	struct s_gnl	*next;
}					t_gnl;


#endif
