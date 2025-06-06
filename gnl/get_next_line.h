/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:44:02 by ls                #+#    #+#             */
/*   Updated: 2025/05/05 14:08:06 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*readbuf(int fd, char *storage);
char	*new_line(char *storage);
char	*cut_storage(char *storage);
size_t	ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *storage, char *buffer);
char	*ft_strchr_gnl(char *s, int c);
int		jumplen(char *storage);
char	*ft_substr_gnl(char *storage, unsigned int start, size_t len);
#endif
