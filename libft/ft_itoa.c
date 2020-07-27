/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:58:55 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/15 15:33:58 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t			size;
	unsigned int	nb;

	size = 1;
	nb = n;
	if (n < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb > 9)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char			*res;
	size_t			i;
	size_t			size;
	unsigned int	nb;

	size = ft_size(n);
	if (!(res = malloc(sizeof(char) * size + 1)))
		return (NULL);
	nb = (n < 0) ? -n : n;
	if (n < 0)
		res[0] = '-';
	i = size - 1;
	while (nb != 0)
	{
		res[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	if (n == 0)
		res[0] = '0';
	res[size] = '\0';
	return (res);
}
