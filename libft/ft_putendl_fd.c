/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:49:53 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/21 17:37:42 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s && fd >= 0 && fd < OPEN_MAX)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
