/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:05:55 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/24 18:01:44 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char *)s1;
	s2_cpy = (unsigned char *)s2;
	if ((!s1 && !s2) || n <= 0)
		return (0);
	else if (!s1)
		return (-s2_cpy[0]);
	else if (!s2)
		return (s1_cpy[0]);
	if (ft_strlen((const char *)s1) == 0 && ft_strlen((const char *)s2) == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (s1_cpy[i] != s2_cpy[i])
			return (s1_cpy[i] - s2_cpy[i]);
		i++;
	}
	return (0);
}
