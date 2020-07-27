/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:48:17 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/20 14:05:17 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_cpy;

	if (!s || n <= 0)
		return (0);
	s_cpy = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_cpy[i] == (unsigned char)c)
			return (&s_cpy[i]);
		i++;
	}
	return (0);
}
