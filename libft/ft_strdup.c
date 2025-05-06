/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:20:15 by tblagoev          #+#    #+#             */
/*   Updated: 2023/11/20 15:44:52 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*s2;

	s1_len = ft_strlen(s1) + 1;
	s2 = (char *) malloc(s1_len);
	if (s2 != NULL)
		ft_strlcpy(s2, s1, s1_len);
	return (s2);
}
