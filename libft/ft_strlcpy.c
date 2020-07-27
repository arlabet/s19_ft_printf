/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:35:58 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/20 17:24:04 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (!dst || !src)
		return (0);
	if (size > ft_strlen(src) + 1)
		ft_memcpy(dst, src, ft_strlen(src) + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, (size - 1));
		dst[size - 1] = '\0';
	}
	return (ft_strlen(src));
}
