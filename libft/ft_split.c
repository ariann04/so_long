/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:08:03 by ls                #+#    #+#             */
/*   Updated: 2023/11/20 15:44:10 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	countwords(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	ft_free_split(char **array)
{
	size_t	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	**fill_array(char **array, const char *s, char c)
{
	int		k;
	size_t	i;
	size_t	j;
	size_t	s_len;

	k = 0;
	i = 0;
	j = 0;
	s_len = ft_strlen(s);
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (j >= s_len)
			array[k++] = "\0";
		else
			array[k++] = ft_substr(s, j, i - j);
		if (array[k - 1] == NULL)
			return (ft_free_split(array), NULL);
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		n_words;

	if (!s)
		return (NULL);
	n_words = countwords(s, c);
	array = malloc((n_words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array = fill_array(array, s, c);
	if (!array)
		return (NULL);
	array[n_words] = NULL;
	return (array);
}
