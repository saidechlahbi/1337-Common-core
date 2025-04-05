/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:32:08 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/25 01:17:23 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clean_strings(char **strings)
{
	int	i;

	i = 0;
	if (strings)
	{
		while (strings[i])
		{
			free(strings[i]);
			i++;
		}
		free(strings);
	}
}

void	clean_game(t_game *game)
{
	free(game->lbaaab);
	ft_clean_strings(game->maps);
	if (game->mlx)
	{
		if (game->img_collect)
			mlx_destroy_image(game->mlx, game->img_collect);
		if (game->img_player)
			mlx_destroy_image(game->mlx, game->img_player);
		if (game->img_exit)
			mlx_destroy_image(game->mlx, game->img_exit);
		if (game->img_wall)
			mlx_destroy_image(game->mlx, game->img_wall);
		if (game->img_floor)
			mlx_destroy_image(game->mlx, game->img_floor);
		if (game->window)
		{
			mlx_clear_window(game->mlx, game->window);
			mlx_destroy_window(game->mlx, game->window);
		}
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

void	out(char *str, t_game *game)
{
	clean_game(game);
	if (str)
		ft_putstr_fd(str, 2);
	exit(1);
}
