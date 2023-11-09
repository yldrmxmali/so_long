/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:57:47 by mehmyild          #+#    #+#             */
/*   Updated: 2023/11/09 22:00:30 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include "minilibx/mlx.h"

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53

static void	ft_putnbr(unsigned int a)
{
	if (a >= 10)
		ft_putnbr(a / 10);
	write(1, &"0123456789"[a % 10], 1);
}

static int	player_register_event(int movement, t_data *data)
{
	if (!movement)
		return (0);
	if (data->map2[data->player_y][data->player_x] == 'C')
	{
		data->map2[data->player_y][data->player_x] = '0';
		data->coin_counter--;
	}
	if (data->coin_counter == 0
		&& data->map2[data->player_y][data->player_x] == 'E')
		game_exit(data);
	data->moves++;
	ft_putnbr(data->moves);
	write(1, "\n", 1);
	return (0);
}

static int	player_register_movement(int key, t_data *data)
{
	if (key == KEY_W)
	{
		data->player_y--;
	}
	else if (key == KEY_A)
	{
		data->character = mlx_xpm_file_to_image(data->mlx_ptr,
				"images/character_left.xpm", &data->x, &data->y);
		data->player_x--;
	}
	else if (key == KEY_S)
	{
		data->player_y++;
	}
	else if (key == KEY_D)
	{
		data->character = mlx_xpm_file_to_image(data->mlx_ptr,
				"images/character.xpm", &data->x, &data->y);
		data->player_x++;
	}
	return (1);
}

int	key_down(int keycode, t_data *data)
{
	int	movement;

	movement = 0;
	if (keycode == KEY_ESC)
		game_exit(data);
	else if (keycode == KEY_W
		&&data->map2[data->player_y - 1][data->player_x] != '1')
		movement = player_register_movement(KEY_W, data);
	else if (keycode == KEY_S
		&& data->map2[data->player_y + 1][data->player_x] != '1')
		movement = player_register_movement(KEY_S, data);
	else if (keycode == KEY_A
		&& data->map2[data->player_y][data->player_x - 1] != '1')
		movement = player_register_movement(KEY_A, data);
	else if (keycode == KEY_D
		&& data->map2[data->player_y][data->player_x + 1] != '1')
		movement = player_register_movement(KEY_D, data);
	player_register_event(movement, data);
	return (0);
}

int	game_exit(t_data *data)
{
	if (!data->map2)
		free_map(data->map2, data->map_height);
	mlx_destroy_image(data->mlx_ptr, data->character);
	mlx_destroy_image(data->mlx_ptr, data->character_left);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->coin);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->background);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit (0);
}
