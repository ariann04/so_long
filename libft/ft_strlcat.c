/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:54:25 by tblagoev          #+#    #+#             */
/*   Updated: 2023/11/20 15:45:44 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;
	size_t	i;

	i = 0;
	if (!dstsize && !dst)
		return (0);
	if (dstsize <= (size_t)ft_strlen(dst))
		return ((dstsize + ft_strlen(src)));
	while (*dst && i < dstsize)
	{
		dst++;
		i++;
	}
	ret = ft_strlcpy(dst, src, dstsize - i);
	return (ret + i);
}
