/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:16:33 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/24 17:55:40 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strcpy(char *dest, char const *src, char c)
{
	int i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int		make_word(char const *s, char c)
{
	int	w;
	int i;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			w++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (w);
}

static char		*fill_word(char const *s, char c)
{
	char	*w;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(w = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	ft_strcpy(w, s, c);
	return (w);
}

static char		**tab_free(char **t, int i)
{
	while (i)
	{
		free(t[i - 1]);
		i--;
	}
	free(t);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (make_word(s, c) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j] && s[j] != c)
		{
			if (!(res[i] = fill_word(&s[j], c)))
				return (tab_free(res, i));
			i++;
			while (s[j] && s[j] != c)
				j++;
		}
	}
	res[i] = NULL;
	return (res);
}
