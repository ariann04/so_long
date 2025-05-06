/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:16:37 by tblagoev          #+#    #+#             */
/*   Updated: 2025/05/05 14:37:51 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

typedef struct	s_game
{
	char	**map;
	int	width;
	int	height;
	int	player_x;
	int	player_y;
}		t_game;

void	print_map(char **map);
char	**load_map(char	*filename, int height);
int	count_lines(char *filename);
void	check_rectangle(t_game *game);
void	free_map(char **map);
void	check_walls_rows(t_game *game);
void	check_walls_col(t_game *game);
#endif
