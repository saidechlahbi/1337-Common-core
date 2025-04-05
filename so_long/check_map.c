/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:32:08 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/25 00:28:26 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_file(t_game *game)
{
	int		i;
	int		j;
	char	*string;

	string = ".ber";
	i = 0;
	j = 0;
	while (game->av[i])
		i++;
	while (string[j])
		j++;
	j--;
	i--;
	while (game->av[i] == string[j])
	{
		i--;
		j--;
	}
	if (j == -1 && i > -1 && game->av[i] != '/')
		return ;
	else
		out("Error\nthe name of the map shoud be end with _.ber\n", game);
}

static void	ft_lines(t_game *game)
{
	char	*string;
	int		fd;

	check_file(game);
	fd = open(game->av, O_RDONLY);
	if (fd == -1)
		out("Error\n", game);
	string = get_next_line(fd);
	while (string)
	{
		game->map_lenght++;
		free(string);
		string = get_next_line(fd);
	}
	close(fd);
}

void	read_the_maps(t_game *game)
{
	int		fd;
	char	*string;
	int		lines;

	ft_lines(game);
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
