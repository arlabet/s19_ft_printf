/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:03:06 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/25 15:55:20 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

int			g_width;
const char	*g_w;
int			g_prec;
const char	*g_p;
int			g_len;

void		ft_check_format(const char *format, va_list argp);
int			ft_printf(const char *format, ...);
void		ft_print_char(va_list argp);
void		ft_print_string(va_list argp);
void		ft_print_pointer(va_list argp);
void		ft_print_num(va_list argp);
void		ft_print_num_uns(va_list argp);
void		ft_print_hexlow(va_list argp);
void		ft_print_hexup(va_list argp);
void		ft_print_space(const char *format, int i, int begin);
void		ft_stock(const char *format, int i, va_list argp);
void		ft_print_space_format(int nbr, int zero, int neg);
void		ft_crop(char *str, int end);
void		ft_reset(void);
int			ft_len_pointer(size_t nbr);
void		ft_stock_star(const char *format, int i, int star, va_list argp);
void		ft_is_space(char c, int begin);
void		ft_print_octal(va_list argp);
int			ft_is_flag(const char *format, int i, int begin);

static void (*g_tab_func[9]) (va_list) = {&ft_print_char, &ft_print_string,
	&ft_print_pointer, &ft_print_num, &ft_print_num, &ft_print_num_uns,
	&ft_print_hexlow, &ft_print_hexup, &ft_print_octal};

#endif
