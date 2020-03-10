/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:25:30 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/20 17:43:02 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		k;
	char	*s_cpy;

	if (!s)
		return (0);
	s_cpy = (char *)s;
	k = (ft_strlen(s) - 1);
	if (c == 0)
		return (&s_cpy[k + 1]);
	while (k >= 0)
	{
		if (s_cpy[k] == c)
			return (&s_cpy[k]);
		k--;
	}
	return (0);
}
