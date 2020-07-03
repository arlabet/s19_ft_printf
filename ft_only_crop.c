/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_crop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 01:43:03 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/04 01:56:58 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_only_crop(char *str, int tmp)
{
	if (tmp < ft_strlen(str))
		ft_putstr_fd(ft_substr(str, 0, tmp), 1);
	else if (tmp >= ft_strlen(str))
		ft_putstr_fd(str, 1);
}