/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:48:12 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/08 20:51:14 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

# define PIXEL 60

typedef struct c_data {
	void			*mlx_ptr;
	void			*win_ptr;
	void			*character;
	void			*character_left;
	void			*background;
	void			*wall;
	void			*coin;
	void			*exit;
	char			**map2;
	char			*line;
	unsigned int	moves;
	int				exit_is_possible;
	int				coin_counter;
	int				x;
	int				y;
	int				player_x;
	int				player_y;
	int				map_height;
	int				map_width;
	int				ply;
	int				exitt;
}	t_data;

int		key_down(int keycode, t_data *data);
void	render_map(t_data *data);
void	free_map(char **map2, size_t height);
int		game_exit(t_data *data);
int		render(t_data *data);
int		key_down(int keycode, t_data *data);
void	start_data(char *map_name);
char	**map_constractor(t_data *data, int fd, int i);
void	ft_reset(char *buffer);
void	load_xpm(t_data *data);
int		flood_fill(t_data *data);
int		map_validation(t_data *data);
int		ft_strlen(char *str);

#endif