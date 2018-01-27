/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_link_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:59:14 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 01:25:53 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	create_link_array(t_lemin *a)
{
	int		i;
	char	**link;
	int		flag;

	i = 0;
	while (i < a->lines)
	{
		if (a->input_type[i] == LEM_LINK)
		{
			flag = 0;
			link = ft_strsplit(a->string_array[i], '-');
			if (add_link(a, link[0], link[1]) == -1)
				flag = 1;
			free_char_array(link);
			if (flag == 1)
			{
				destroy_antfarm(a);
				exit(0);
			}
		}
		i++;
	}
	return ;
}
