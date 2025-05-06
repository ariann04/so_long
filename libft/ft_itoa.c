/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:02:17 by tblagoev          #+#    #+#             */
/*   Updated: 2023/10/10 03:45:48 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		i++;
	while (n <= -10 || n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = num_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		if (n < 0)
			str[len - 1] = -(n % 10) + '0';
		else
			str[len - 1] = n % 10 + '0';
		len--;
		n /= 10;
	}
	return (str);
}
