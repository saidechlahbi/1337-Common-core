/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:32:08 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/25 01:12:36 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_textures(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&(int){64}, &(int){64});
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &(int){64}, &(int){64});
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&(int){64}, &(int){64});
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&(int){64}, &(int){64});
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&(int){64}, &(int){64});
	if (!game->img_player || !game->img_collect || !game->img_exit
		|| !game->img_wall || !game->img_floor)
		out("Error\n", game);
}

static void	helper(t_game *game, int i, int j)
{
	if (game->maps[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->img_wall,
			j * 64, i * 64);
	else if (game->maps[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img_floor, j * 64, i * 64);
	else if (game->maps[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img_player, j * 64, i * 64);
	else if (game->maps[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img_collect, j * 64, i * 64);
	else if (game->maps[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->img_exit,
			j * 64, i * 64);
}

void	rander_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->maps[i])
	{
		j = 0;
		while (game->maps[i][j])
		{
			helper(game, i, j);
			j++;
		}
		i++;
	}
}

int	handle(t_game *game)
{
	out("game closed\n", game);
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (write(2, "Error\n", 6), 1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	initialisation(game);
	game->av = av[1];
	filter_maps(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		out("Error\n", game);
	game->window = mlx_new_window(game->mlx, game->map_width * 64,
			game->map_lenght * 64, "so_long");
	if (!game->window)
		out("Error\n", game);
	load_textures(game);
	rander_map(game);
	mlx_hook(game->window, 17, 0, handle, game);
	mlx_key_hook(game->window, handle_player, game);
	mlx_loop(game->mlx);
}
