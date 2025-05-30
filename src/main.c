/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:02:45 by tblagoev          #+#    #+#             */
/*   Updated: 2025/05/30 21:16:44 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Less than 2 arguments");
		return (1);
	}
	if (init_game(&game, argv[1]))
		return (1);
	//print_map(game.map);
	test_movements(&game);
	return (0);
}
