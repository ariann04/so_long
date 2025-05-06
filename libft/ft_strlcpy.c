/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:30:56 by tblagoev          #+#    #+#             */
/*   Updated: 2023/11/20 15:46:00 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (src != NULL && dst != NULL && dstsize != 0)
	{
		i = 0;
		while ((i < dstsize - 1) && (i < srclen))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}
