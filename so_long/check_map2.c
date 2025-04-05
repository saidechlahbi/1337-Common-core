/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:32:08 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/25 00:31:36 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->maps[i])
	{
		j = 0;
		while (game->maps[i][j])
		{
			if (game->maps[i][j] == '1' || game->maps[i][j] == 'C'
				|| game->maps[i][j] == 'E' || game->maps[i][j] == 'P'
				|| game->maps[i][j] == '0')
				j++;
			else
				out("Error\nmap have forein elements\n", game);
		}
		i++;
	}
}

static void	nb_elements(t_game *game)
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
				game->player.p_count++;
			else if (game->maps[i][j] == 'E')
				game->e_cout++;
			else if (game->maps[i][j] == 'C')
				game->c_count++;
			j++;
		}
		i++;
	}
	if (game->player.p_count == 1 && game->c_count && game->e_cout == 1)
		return ;
	else
		out("Error\nmap invalid, some items do not meet the requirements\n",
			game);
}

static void	nb_lines(t_game *game)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(game->maps[0]);
	game->map_width = size;
	if (game->map_lenght < 3)
		out("Error\nmap invalid, must be at least 3 lines\n", game);
	while (game->maps[i])
	{
		if (ft_strlen(game->maps[i]) != size)
			out("Error\nmap invalid, all lines must be the same size\n", game);
		i++;
	}
}

static void	surrounded_by_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->maps[i][j] && game->maps[i][j] == '1')
		j++;
	if (game->maps[i][j])
		out("Error\nmap invalid, the map must be surrounded by walls\n", game);
	j = 0;
	while (game->maps[i])
	{
		if (game->maps[i + 1] == NULL)
			break ;
		if (game->maps[i][0] != '1' || game->maps[i][ft_strlen(game->maps[i])
			- 1] != '1')
			out("Error\nmap invalid, the map must be surrounded by walls\n",
				game);
		i++;
	}
	j = 0;
	while (game->maps[i][j] && game->maps[i][j] == '1')
		j++;
	if (game->maps[i][j])
		out("Error\nmap invalid, the map must be surrounded by walls\n", game);
}

void	filter_maps(t_game *game)
{
	read_the_maps(game);
	elements(game);
	nb_elements(game);
	nb_lines(game);
	surrounded_by_walls(game);
	check_path(game);
}
