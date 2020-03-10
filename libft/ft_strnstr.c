/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:48:47 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/21 17:34:54 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t l;
	size_t b;

	if (!ft_strlen(needle) || !haystack)
		return ((char *)haystack);
	b = 0;
	while (haystack[b] && b < len)
	{
		l = 0;
		while (needle[l] && haystack[b + l] && needle[l] == haystack[b + l]
			&& (b + l) < len)
			l++;
		if (!needle[l])
			return ((char*)&haystack[b]);
		b++;
	}
	return (0);
}
