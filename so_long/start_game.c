/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:00:50 by mehmyild          #+#    #+#             */
/*   Updated: 2023/11/09 22:00:13 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include <fcntl.h>
#include <unistd.h>

static int	filename_check(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'r' && str[i - 1] == 'e'
		&& str[i - 2] == 'b' && str[i - 3] == '.')
	{
		return (0);
	}
	write(2, "ERROR_MAP_NAME\n", 15);
	return (1);
}

static void	game_init(t_data *data)
{
	data->coin_counter = 0;
	data->exitt = 0;
	data->ply = 0;
	data->moves = 0;
}

static	void	game_run(t_data *data)
{
	mlx_hook(data->win_ptr, 2, 0, key_down, data);
	mlx_hook(data->win_ptr, 17, 0, game_exit, data);
	mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_loop (data->mlx_ptr);
}

static	void	error(t_data *data)
{
	write(2, "ERROR\n", 6);
	free_map(data->map2, data->map_height);
	exit(1);
}

void	start_data(char *map_name)
{
	t_data	data;
	int		fd;
	int		i;

	i = -1;
	if (filename_check(map_name))
		return ;
	game_init(&data);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (write(2, "Wrong_file_path\n", 16), exit(1));
	data.map2 = map_constractor(&data, fd, i);
	close(fd);
	if (map_validation(&data))
		return (error(&data));
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (error(&data));
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			data.map_width * PIXEL, data.map_height * PIXEL, "so_long");
	if (!data.win_ptr)
		return (error(&data));
	load_xpm(&data);
	game_run(&data);
}
