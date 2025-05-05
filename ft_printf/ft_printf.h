/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:23:13 by ls                #+#    #+#             */
/*   Updated: 2024/01/08 12:23:53 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	print_char(int c);
int	print_str(char *str);
int	print_integer(long n, int base);
int	print_digit(unsigned int n, int base);
int	print_digit_alt(unsigned int n, int base);
int	print_unsigned_decimal(unsigned int n, int base);
int	print_format(char specifier, va_list ap);
int	print_void(unsigned long address, int base);
int	ft_printf(char const *format, ...);

#endif
