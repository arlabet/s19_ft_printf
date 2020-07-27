/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:23:23 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/22 21:45:39 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char const *set, char c)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (!s1 || !set)
		return (0);
	if (set == 0)
	{
		res = (char *)s1;
		return (res);
	}
	end = ft_strlen(s1);
	start = 0;
	while (ft_isinset(set, s1[start]))
		start++;
	while (ft_isinset(set, s1[end - 1]))
		end--;
	if (end <= start)
		end = start;
	res = ft_substr(s1, start, (end - start));
	return (res);
}
