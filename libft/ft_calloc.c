/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:04:38 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/20 13:19:59 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *tab;

	if (!(tab = malloc(nmemb * size)))
		return (NULL);
	ft_bzero(tab, (nmemb * size));
	return (tab);
}
