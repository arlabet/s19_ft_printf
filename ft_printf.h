/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:03:06 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/02 03:54:38 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

int		g_crop;
void	ft_apply_type(const char *format, int i, va_list argp);
int		ft_check_type(const char format);
void	ft_check_format(const char *format, va_list argp);
int		ft_printf(const char *format, ...);
void	ft_print_char(int car, const char *format, int i);
int		ft_treat_space(const char *format, int end, int fo);
void	ft_print_string(char *str, const char *format, int i);
void	ft_print_pointer(size_t p, const char *format, int i);
void	ft_print_num(int nbr, const char *format, int i);
void	ft_print_num_uns(unsigned int nbr, const char *format, int i);
void	ft_print_hexlow(unsigned int nbr, const char *format, int i);
void	ft_print_hexup(unsigned int nbr, const char *format, int i);
int     ft_width(char *width);
void	ft_print_spaces(int nbr, int before_after_zero);
void	ft_print_spaces_format(int nbr);
int		ft_is_flag(char c);
int		ft_to_skip(const char *format, int i);
int		crop_space (const char *format, int i);
void	print_crop_space(char *str, int tmp, int i, const char *format);

#endif
