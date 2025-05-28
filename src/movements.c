#include "so_long.h"

void	init_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_y = i;
				game->player_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	target;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_y < 0 || new_y >= game->height || new_x < 0
			|| new_x >= game->width)
		return ;
	target = game->map[new_y][new_x];
	if (target == '1')
		return ;
	if (target == 'E')
		ft_printf("You have reached the exit\n");
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_y = new_y;
	game->player_x = new_x;
	ft_printf("Move made\n");
	print_map(game->map);
}

void	test_movements(t_game *game)
{
	char	input;

	ft_printf("Controls: W A S D | Q for exit\n");
	while (1)
	{
		ft_printf("Your move: ");
		if (read(0, &input, 1) <= 0)
			break ;
		if (input == 'q' || input == 'Q')
			break ;
		if (input == 'w' || input == 'W')
			move_player(game, 0, -1);
		else if (input == 's' || input == 'S')
			move_player(game, 0, 1);
		else if (input == 'a' || input == 'A')
			move_player(game, -1, 0);
		else if (input == 'd' || input == 'D')
			move_player(game, 1, 0);
		while(1)
		{
			char	trash;

			if (read(0, &trash, 1) <= 0 || trash == '\n')
				break;
		}
	}
}
