/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:54:37 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/27 04:55:17 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	main(int ac, char **av)
{
	t_lemin	*a;

	a = ft_memalloc(sizeof(t_lemin));
	if (a == NULL)
		return (ft_printf("ERROR\n"));
	cmd_line_opt(ac, av, a);
	get_input(a);
	check_duplicate_room_names(a);
	create_room_array(a);
	create_link_array(a);
	bfs_is_map_valid(a);
	create_ant_array(a);
	if (a->hide_map == 0)
		ft_printf("%s\n", a->raw_input);
	bfs_generate_paths(a);
	bfs_display_shortest_path(a);
	display_result(a);
	destroy_antfarm(a);
	return (0);
}
