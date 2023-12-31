/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:49:31 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/08 20:01:21 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

static char	*put_line(char *buffer, int *bf)
{
	char	*line;
	int		buffer_index;
	int		line_length;
	int		index;

	buffer_index = (*bf);
	line_length = 0;
	index = buffer_index;
	while (buffer[buffer_index] != '\n' && buffer[buffer_index] != '\0')
	{
		line_length++;
		buffer_index++;
	}
	(*bf) += line_length + 1;
	buffer_index = index;
	index = 0;
	line = (char *) malloc(sizeof(char) * (line_length + 1));
	if (!line)
		return (NULL);
	while (index < line_length)
		line[index++] = buffer[buffer_index++];
	line[index] = '\0';
	return (line);
}

static int	count_nl(char *buffer, int size)
{
	int	enter;
	int	i;

	i = 0;
	enter = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
			enter++;
		i++;
	}
	return (enter + 1);
}

static char	**map_builder(char *buffer, int size, t_data *data)
{
	int		index;
	int		bf;
	char	**map;

	index = 0;
	bf = 0;
	data->map_height = count_nl(buffer, size);
	map = (char **) malloc(sizeof(char *) * data->map_height);
	if (!map)
		return (NULL);
	while (index < data->map_height)
	{
		map[index] = put_line(buffer, &bf);
		index++;
	}
	return (map);
}

char	**map_constractor(t_data *data, int fd, int i)
{
	char	buffer[10000];
	int		bytes;

	bytes = 1;
	ft_reset(buffer);
	while (bytes)
	{
		bytes = read(fd, &buffer[++i], 1);
		if (bytes == -1)
		{
			write(2, "ERROR\n", 6);
			close(fd);
			exit(1);
		}
	}
	if (i > 10000)
	{
		write(2, "Map is to big!\n", 15);
		close(fd);
		exit(1);
	}
	return (map_builder(buffer, i, data));
}
