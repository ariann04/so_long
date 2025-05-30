/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:37:32 by tblagoev          #+#    #+#             */
/*   Updated: 2025/05/30 21:14:17 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"
#include <stdbool.h>

static void	handle_input(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_W)
		move_player(game, 0, -1);
	else if (keydata.key == MLX_KEY_S)
		move_player(game, 0, 1);
	else if (keydata.key == MLX_KEY_A)
		move_player(game, -1, 0);
	else if (keydata.key == MLX_KEY_D)
		move_player(game, 1, 0);
	else if (game->map[game->player_y][game->player_x] == 'E')
		return;
	render_map(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long map.ber\n");
		return (1);
	}
	if (init_game(&game, argv[1]))
		return (1);

	game.mlx = mlx_init(game.width * 64, game.height * 64, "so_long", false);
	if (!game.mlx)
		return (1);

	load_images(&game);
	render_map(&game);

	mlx_key_hook(game.mlx, &handle_input, &game);
	mlx_loop(game.mlx);

	mlx_terminate(game.mlx);
	free_map(game.map);
	return (0);
}
