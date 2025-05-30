/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:04:33 by tblagoev          #+#    #+#             */
/*   Updated: 2025/05/30 20:53:35 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_game *game, char tile, int x, int y)
{
	mlx_image_to_window(game->mlx, game->img_bg, x * 64, y * 64);
	if (tile == '1')
		mlx_image_to_window(game->mlx, game->img_wall, x * 64, y * 64);
	if (tile == 'P')
		mlx_image_to_window(game->mlx, game->img_player, x * 64, y * 64);
	if (tile == 'C')
		mlx_image_to_window(game->mlx, game->img_collect, x * 64, y * 64);
	if (tile == 'E')
		mlx_image_to_window(game->mlx, game->img_exit, x * 64, y * 64);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	char	tile;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			tile = game->map[y][x];
			render_tile(game, tile, x, y);
			x++;
		}
		y++;
	}
}

void	init_images(t_game *game)
{
	game->img_bg = mlx_texture_to_image(game->mlx, mlx_load_png("textures/64x64BG.png"));
	game->img_wall = mlx_texture_to_image(game->mlx, mlx_load_png("textures/64x64meteoritos.png"));
	game->img_player = mlx_texture_to_image(game->mlx, mlx_load_png("textures/64x64cohete.png"));
	game->img_collect = mlx_texture_to_image(game->mlx, mlx_load_png("textures/64x64sun.png"));
	game->img_exit = mlx_texture_to_image(game->mlx, mlx_load_png("textures/64x64portal.png"));
}

void	load_images(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("textures/64x64BG.png");
	game->img_bg = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);

	texture = mlx_load_png("textures/64x64meteoritos.png");
	game->img_wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);

	texture = mlx_load_png("textures/64x64cohete.png");
	game->img_player = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);

	texture = mlx_load_png("textures/64x64sun.png");
	game->img_collect = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);

	texture = mlx_load_png("textures/64x64portal.png");
	game->img_exit = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}
