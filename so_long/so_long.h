/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:32:08 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/25 01:25:32 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct s_player
{
	int			x;
	int			y;
	int			p_count;
	int			p_steps;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*img_player;
	void		*img_collect;
	void		*img_wall;
	void		*img_floor;
	void		*img_exit;
	int			c_count;
	int			e_cout;
	char		**maps;
	int			map_lenght;
	int			map_width;
	t_player	player;
	char		*av;
	int			*lbaaab;
}				t_game;

/*tools*/
void			ft_putstr_fd(char *s, int fd);
void			initialisation(t_game *game);

/*la filtration de map*/
void			read_the_maps(t_game *game);
void			check_path(t_game *game);
void			filter_maps(t_game *game);

void			rander_map(t_game *game);
int				handle_player(int key, t_game *game);

/* clean */
void			ft_clean_strings(char **strings);
void			out(char *str, t_game *game);
void			clean_game(t_game *game);

/* get next line*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char			*ft_calloc(size_t nmemb, size_t size);
char			*get_next_line(int fd);
int				ft_strlen(char *s);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*get_last_rest_of_line(char *str);
char			*get_rest_for_next_line(char *str);
char			*get_next_line(int fd);

#endif