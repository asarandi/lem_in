/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 01:21:20 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/30 19:26:23 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strtoupper(char *s)
{
	size_t	i;
	size_t	k;

	i = ft_strlen(s);
	k = 0;
	while (k < i)
	{
		if ((s[k] >= 'a') && (s[k] <= 'z'))
			s[k] = s[k] - 0x20;
		k++;
	}
	return (s);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*mem;

	mem = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (mem == NULL)
		return (NULL);
	return (ft_strcpy(mem, s1));
}
