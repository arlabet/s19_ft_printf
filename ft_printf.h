/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:03:06 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/01 01:52:11 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

void	ft_apply_type(const char *format, int i, va_list argp);
int		ft_check_type(const char format);
int		ft_check_format(const char *format, va_list argp);
int		ft_printf(const char *format, ...);
void	ft_print_char(int car, const char *format, int i);
void	ft_treat_space(const char *format, int i);
void	ft_print_string(char *str);
void	ft_print_pointer(size_t p);
void	ft_print_num(int nbr);
void	ft_print_num_uns(unsigned int nbr);
void	ft_print_hexlow(unsigned int nbr);
void	ft_print_hexup(unsigned int nbr);
int     ft_width(char *width);
void	ft_print_spaces(int nbr, int before_after_zero);

#endif
