/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:32:08 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/19 02:04:28 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->maps[i])
	{
		j = 0;
		while (game->maps[i][j])
		{
			if (game->maps[i][j] == 'P')
			{
				game->player.y = i;
				game->player.x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	flood_fill(char **tab, int x, int y)
{
	if (tab[x][y] == '1' || tab[x][y] == 'F')
		return ;
	tab[x][y] = 'F';
	flood_fill(tab, x + 1, y);
	flood_fill(tab, x, y + 1);
	flood_fill(tab, x, y - 1);
	flood_fill(tab, x - 1, y);
}

static void	ft_read(t_game *game)
{
	int		fd;
	char	*string;
	int		lines;

	game->maps = malloc(sizeof(char *) * (game->map_lenght + 1));
	if (!game->maps)
		out("Error\n", game);
	fd = open(game->av, O_RDONLY);
	if (fd == -1)
		out("Error\n", game);
	string = get_next_line(fd);
	lines = 0;
	while (string)
	{
		game->maps[lines] = string;
		lines++;
		string = get_next_line(fd);
	}
	game->maps[lines] = NULL;
	close(fd);
}

void	check_path(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	get_player_position(game);
	flood_fill(game->maps, game->player.x, game->player.y);
	while (game->maps[i])
	{
		j = 0;
		while (game->maps[i][j])
		{
			if (game->maps[i][j] == 'C' || game->maps[i][j] == 'E')
				out("Error\nmap invalid, the map must be surrounded by walls\n",
					game);
			j++;
		}
		i++;
	}
	ft_clean_strings(game->maps);
	ft_read(game);
}
