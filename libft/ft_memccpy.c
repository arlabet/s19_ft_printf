/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:59:04 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/21 19:14:04 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_cpy;
	unsigned char	*dest_cpy;

	if (!dest || !src)
		return (0);
	src_cpy = (unsigned char *)src;
	dest_cpy = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		if (src_cpy[i] == (unsigned char)c)
		{
			return (&dest[i + 1]);
		}
		i++;
	}
	return (0);
}
