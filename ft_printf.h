/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:03:06 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/20 22:10:58 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"



void	ft_check_format(const char *format, va_list argp);
int		ft_printf(const char *format, ...);
void	ft_print_char(va_list argp);
void	ft_print_string(va_list argp);
void	ft_print_pointer(va_list argp);
void	ft_print_num(va_list argp);
void	ft_print_num_uns(va_list argp);
void	ft_print_hexlow(va_list argp);
void	ft_print_hexup(va_list argp);
void	ft_print_space(const char *format, int i);

static void (*g_tab_func[7]) (va_list) = {&ft_print_char, &ft_print_string,
	&ft_print_pointer, &ft_print_num, &ft_print_num_uns, &ft_print_hexlow, 
	&ft_print_hexup};

#endif
