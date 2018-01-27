/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_enqueue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:10:13 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/26 22:10:42 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	bfs_enqueue(t_room *root, t_room *next)
{
	next->parent = root;
	next->depth = root->depth + 1;
	while (root->child != NULL)
	{
		root = root->child;
	}
	root->child = next;
	next->child = NULL;
	return ;
}
