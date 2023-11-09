/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:59:01 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/08 19:45:39 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 2)
		start_data(av[1]);
	else
		write(2, "invalid argument", 16);
	return (0);
}
