/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:20:06 by tblagoev          #+#    #+#             */
/*   Updated: 2024/01/09 18:09:52 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_integer(-n, base) + 1);
	}
	else if (n < (unsigned int)base)
		return (print_char(symbols[n]));
	else
	{
		count = print_integer(n / base, base);
		return (count + print_integer(n % base, base));
	}
}

int	print_digit(unsigned int n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < (unsigned int)base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}

int	print_digit_alt(unsigned int n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	if (n < (unsigned int)base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit_alt(n / base, base);
		return (count + print_digit_alt(n % base, base));
	}
}

int	print_unsigned_decimal(unsigned int n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789";
	if (n < (unsigned int)base)
		return (print_char(symbols[n]));
	else
	{
		count = print_unsigned_decimal(n / base, base);
		return (count + print_unsigned_decimal(n % base, base));
	}
}

int	print_void(unsigned long address, int base)
{
	static int	count;
	char		*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (address >= (unsigned long)base)
	{
		print_void(address / base, base);
		address = address % base;
	}
	if (count == 0)
		count += write(1, "0x", 2);
	count++;
	write(1, &symbols[address], 1);
	return (count);
}
