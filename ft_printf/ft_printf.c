/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:46:21 by tblagoev          #+#    #+#             */
/*   Updated: 2024/01/28 15:42:13 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_integer((long)va_arg(ap, int), 10);
	else if (specifier == 'x')
		count += print_digit((long)va_arg(ap, unsigned int), 16);
	else if (specifier == 'X')
		count += print_digit_alt((long)va_arg(ap, unsigned int), 16);
	else if (specifier == 'u')
		count += print_unsigned_decimal((unsigned int)va_arg(ap,
					unsigned int), 10);
	else if (specifier == '%')
		return (write(1, "%", 1));
	else if (specifier == 'p')
		count += print_void((unsigned long)va_arg(ap, void *), 16);
	else
		return (write(1, &specifier, 1));
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write (1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

/*int	main (void)
{
	int	print_length;
	int	ft_print_length;
	char	c = 'a';
	char	*s = "Alea iacta est";
	int		d = -42;

	print_length = 0;
	ft_print_length = 0;
	// No format
	print_length = printf("EXPECTED: Hello World!\n") - 11;
	printf("EXPECTED RETURN: %d\n", print_length);
	ft_print_length = ft_printf("FT_USER_: Hello World!\n") - 11;
	printf("FT_USER_ RETURN: %d\n", ft_print_length);

	if (print_length - ft_print_length == 0)
		printf("\n\tOK!\n");
	else
		printf("\n\tKO!\n");

	// %c
	print_length = printf("EXPECTED: %c\n", c) - 11;
	printf("EXPECTED RETURN: %d\n", print_length);
	ft_print_length = ft_printf("FT_USER_: %c\n", c) - 11;
	printf("FT_USER_ RETURN: %d\n", ft_print_length);

	if (print_length - ft_print_length == 0)
		printf("\n\tOK!\n");
	else
		printf("\n\tKO!\n");

	// %s
	print_length = printf("EXPECTED: %s\n", s) - 11;
	printf("EXPECTED RETURN: %d\n", print_length);
	ft_print_length = ft_printf("FT_USER_: %s\n", s) - 11;
	printf("FT_USER_ RETURN: %d\n", ft_print_length);

	if (print_length - ft_print_length == 0)
		printf("\n\tOK!\n");
	else
		printf("\n\tKO!\n");

	// %p
	print_length = printf("EXPECTED: %p\n", s) - 11;
	printf("EXPECTED RETURN: %d\n", print_length);
	ft_print_length = ft_printf("FT_USER_: %p\n", s) - 11;
	printf("FT_USER_ RETURN: %d\n", ft_print_length);

	if (print_length - ft_print_length == 0)
		printf("\n\tOK!\n");
	else
		printf("\n\tKO!\n");

	// %d
	print_length = printf("EXPECTED: %d\n", d) - 11;
	printf("EXPECTED RETURN: %d\n", print_length);
	ft_print_length = ft_printf("FT_USER_: %d\n", d) - 11;
	printf("FT_USER_ RETURN: %d\n", ft_print_length);

	if (print_length - ft_print_length == 0)
		printf("\n\tOK!\n");
	else
		printf("\n\tKO!\n");

	// %i
	print_length = printf("EXPECTED: %i\n", d) - 11;
	printf("EXPECTED RETURN: %d\n", print_length);
	ft_print_length = ft_printf("FT_USER_: %i\n", d) - 11;
	printf("FT_USER_ RETURN: %d\n", ft_print_length);

	if (print_length - ft_print_length == 0)
		printf("\n\tOK!\n");
	else
		printf("\n\tKO!\n");

	// %u
	print_length = printf("EXPECTED: %u\n", d) - 11;
	printf("EXPECTED RETURN: %d\n", print_length);
	ft_print_length = ft_printf("FT_USER_: %u\n", d) - 11;
	printf("FT_USER_ RETURN: %d\n", ft_print_length);

	if (print_length - ft_print_length == 0)
		printf("\n\tOK!\n");
	else
		printf("\n\tKO!\n");

	// %x
	print_length = printf("EXPECTED: %x\n", d) - 11;
	printf("EXPECTED RETURN: %d\n", print_length);
	ft_print_length = ft_printf("FT_USER_: %x\n", d) - 11;
	printf("FT_USER_ RETURN: %d\n", ft_print_length);

	if (print_length - ft_print_length == 0)
		printf("\n\tOK!\n");
	else
		printf("\n\tKO!\n");

	print_length = printf("EXPECTED: %x\n", 0) - 11;
	printf("EXPECTED RETURN: %d\n", print_length);
	ft_print_length = ft_printf("FT_USER_: %x\n", 0) - 11;
	printf("FT_USER_ RETURN: %d\n", ft_print_length);

	if (print_length - ft_print_length == 0)
		printf("\n\tOK!\n");
	else
		printf("\n\tKO!\n");

	// %X
	print_length = printf("EXPECTED: %X\n", d) - 11;
	printf("EXPECTED RETURN: %d\n", print_length);
	ft_print_length = ft_printf("FT_USER_: %X\n", d) - 11;
	printf("FT_USER_ RETURN: %d\n", ft_print_length);

	if (print_length - ft_print_length == 0)
		printf("\n\tOK!\n");
	else
		printf("\n\tKO!\n");

	// %%
	print_length = printf("EXPECTED: %%\n") - 11;
	printf("EXPECTED RETURN: %d\n", print_length);
	ft_print_length = ft_printf("FT_USER_: %%\n") - 11;
	printf("FT_USER_ RETURN: %d\n", ft_print_length);

	if (print_length - ft_print_length == 0)
		printf("\n\tOK!\n");
	else
		printf("\n\tKO!\n");
	return (0);
}
*/
/*int	main()
{
	char		c = 'T';
	char		*s = "Hola, mundo!";
	long		nb = 12345678;
	int			n = 123;
	char		*str = "Hi";
	char		*ptr = NULL;

	ft_printf("The char written is %c\n", c);
	ft_printf("The str written is %s\n", s);
	ft_printf("The integer written is %i and the other one is %d\n", nb, n);
	ft_printf("The unsigned hexadecimal written is %x\n", n);
	ft_printf("The unsigned alt hexadecimal written is %X", n);
	ft_printf("The pointer written is %p\n", (void *)ptr);
	ft_printf("The pointer written is %p\n", (void *)str);
	ft_printf("The str written is %s", (void *)ptr);
}
int	average(int n, ...)
{
	va_list	ap;
	int		total;
	int		i;

	va_start(ap, n);
	total = 0;
	i = 0;
	while (i < n)
	{
		total += va_arg(ap, int);
		i++;
	}
	return ((float)total / n);
}

int	main()
{
	float	average_age;

	average_age = average(3, 10, 15, 20);
	printf("The average age of those 3 ppl is %f\n", average_age);
}
*/
