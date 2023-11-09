/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:51:19 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/06 20:39:57 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map2, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(map2[i]);
		map2[i] = (void *)0;
		i++;
	}
	free(map2);
	map2 = (void *)0;
}

static char	*ft_strdup(char *a)
{
	int		i;
	char	*ret;

	ret = malloc(sizeof(char) * ft_strlen(a));
	if (!ret)
		return (NULL);
	i = -1;
	while (a[++i])
		ret[i] = a[i];
	return (ret);
}

static int	check_movement(t_data *data, size_t y, size_t x)
{
	if (data->map2[y][x] == '1')
		return (0);
	if (data->map2[y][x] == 'C')
		data->coin_counter--;
	if (data->map2[y][x] == 'E')
		data->exit_is_possible = 1;
	data->map2[y][x] = '1';
	if (check_movement(data, y + 1, x))
		return (1);
	if (check_movement(data, y - 1, x))
		return (1);
	if (check_movement(data, y, x + 1))
		return (1);
	if (check_movement(data, y, x - 1))
		return (1);
	return (0);
}

int	flood_fill(t_data *data)
{
	t_data	temp;
	int		i;

	temp.map_height = data->map_height;
	temp.map_width = data->map_width;
	temp.coin_counter = data->coin_counter;
	temp.player_x = data->player_x;
	temp.player_y = data->player_y;
	temp.exit_is_possible = 0;
	temp.map2 = (char **)malloc(temp.map_height * sizeof(char *));
	if (!temp.map2)
		return (1);
	i = -1;
	while (++i < temp.map_height)
		temp.map2[i] = ft_strdup(data->map2[i]);
	check_movement(&temp, temp.player_y, temp.player_x);
	if (!(temp.exit_is_possible == 1 && temp.coin_counter == 0))
	{
		free_map(temp.map2, temp.map_height);
		return (1);
	}
	free_map(temp.map2, temp.map_height);
	return (0);
}
