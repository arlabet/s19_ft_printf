/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:22:39 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/20 15:55:12 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	i = 0;
	if (!s)
		return (0);
	dest = (unsigned char *)s;
	while (i < n)
	{
		dest[i] = c;
		i++;
	}
	return (s);
}
