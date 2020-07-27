/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:54:20 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/20 15:47:21 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	if (!dest || !src)
		return (0);
	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	i = n;
	if (dest_cpy > src_cpy && dest_cpy < (src_cpy + n))
		while (n > 0)
		{
			dest_cpy[n - 1] = src_cpy[n - 1];
			n--;
		}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
