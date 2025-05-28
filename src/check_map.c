/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:14:20 by tblagoev          #+#    #+#             */
/*   Updated: 2025/05/05 16:29:29 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_rectangle(t_game *game)
{
	int	i;
	size_t	width;

	i = 0;
	width = ft_strlen(game->map[0]);
	game->width = width;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != width)
		{
			write(1, "Error\n", 6);
			free_map(game->map);
			exit(1);
		}
		i++;
	}
}

void	check_walls_rows(t_game *game)
{
	int	i;
	size_t	last_row;

	i = 0;
	last_row = game->height - 1;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[last_row][i] != '1')
		{
			write(1, "Error\n", 6);
			free_map(game->map);
			exit(1);
		}
		i++;
	}
}
void	check_walls_col(t_game *game)
{
	int		i;
	size_t	last_col;

	i = 0;
	last_col = game->width - 1;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][last_col] != '1')
		{
			write(1, "Error\n", 6);
			free_map(game->map);
			exit(1);
		}
		i++;
	}
}

static void	count_elements_line(char *line, int *player, int *exit, int *collectibles)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'P')
			(*player)++;
		if(line[j] == 'E')
			(*exit)++;
		if (line[j] == 'C')
			(*collectibles)++;
		j++;
	}
}

void	check_elements(t_game *game)
{
	int	i;
	int	player;
	int	exits;
	int	collectibles;

	player = 0;
	exits = 0;
	collectibles = 0;
	i = 0;
	while (game->map[i])
	{
		count_elements_line(game->map[i], &player, &exits, &collectibles);
		i++;
	}
	if (player != 1 || exits != 1 || collectibles == 0)
	{
		write(1, "Error\n", 6);
		free_map(game->map);
		exit(1);
	}
}
