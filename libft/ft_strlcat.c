/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:44:35 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/20 17:14:00 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t s;
	size_t d;
	size_t j;

	if (!src || !dst)
		return (ft_strlen(dst) + ft_strlen(src));
	j = 0;
	s = ft_strlen(src);
	d = ft_strlen(dst);
	if (size <= d)
		s = s + size;
	else
		s = s + d;
	while (d + 1 < size && src[j])
	{
		dst[d] = src[j];
		d++;
		j++;
	}
	dst[d] = '\0';
	return (s);
}
