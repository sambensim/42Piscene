/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:51:58 by ssimmons          #+#    #+#             */
/*   Updated: 2024/03/27 18:14:44 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "biggest_square.h"

void	ft_putchar(char character)
{
	write(1, &character, 1);
}

int	is_number(char character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}

int	read_map_length(char *map)
{
	int	i;
	int	length;
	int	endline;

	endline = 0;
	while (map[endline] != '\n')
		endline++;
	endline -= 3;
	i = 0;
	length = 0;
	while (is_number(map[i]) && i < endline)
	{
		length *= 10;
		length += (map[i] - '0');
		i++;
	}
	return (length);
}

int	find_map_length(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (ft_sqrt(i));
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}
