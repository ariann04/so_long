/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:05:37 by tblagoev          #+#    #+#             */
/*   Updated: 2025/05/30 21:06:57 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     init_game(t_game *game, char *map_path)
{
        int     height;

        height = count_lines(map_path);
        if (height <= 0)
        {
                ft_printf("Error reading map\n");
                return (1);
        }
        game->height = height;
        game->map = load_map(map_path, height);
        if (!game->map)
        {
                ft_printf("Error loading map\n");
                return (1);
        }
        check_rectangle(game);
        check_walls_rows(game);
        check_walls_col(game);
        check_elements(game);
        check_path(game);
        init_player_position(game);
        return (0);
}
