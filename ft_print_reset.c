/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 00:42:57 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/21 00:57:50 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_reset(int g_width, const char	*g_w, int g_prec, const char *g_p)
{
	g_width = 0;
	g_w = NULL;
	g_prec = 0;
	g_p = NULL;
}