/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:02:45 by tblagoev          #+#    #+#             */
/*   Updated: 2025/05/05 16:27:16 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int	height;

	if (argc != 2)
	{
		ft_printf("Less than 2 arguments\n");
		return (1);
	}
	height = count_lines(argv[1]);
	if (height <= 0)
	{
		ft_printf("Error reading map\n");
		return (1);
	}
	game.height = height;
	game.map = load_map(argv[1], height);
	if (!game.map)
	{
		ft_printf("Error loading map\n");
		return (1);
	}
	check_rectangle(&game);
	check_walls_rows(&game);
	check_walls_col(&game);
	print_map(game.map);
	return (0);
}
