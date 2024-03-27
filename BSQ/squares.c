/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squares.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:52:07 by ssimmons          #+#    #+#             */
/*   Updated: 2024/03/27 16:50:56 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "biggest_square.h"

int	ft_sqrt(int nb)
{
	int	guess;

	guess = 0;
	while ((guess * guess) <= nb)
		guess++;
	return (guess - 1);
}

int	is_square_valid(struct s_mapdata md, int corner_map_pos, int square_length)
{
	int		square_pos;
	int		map_pos;
	char	empty_char;

	empty_char = md.symbols[0];
	map_pos = corner_map_pos;
	square_pos = 0;
	while (square_pos < square_length * square_length)
	{
		map_pos = corner_map_pos + square_pos % square_length + \
			(square_pos / square_length) * md.length;
		if (md.contents[map_pos] != empty_char)
		{
			return (0);
		}
		square_pos++;
	}
	return (1);
}

void	fill_square(struct s_mapdata md, int *solution)
{
	int		square_x;
	int		square_y;
	int		square_length;
	int		corner_map_pos;
	char	filled_char;

	square_y = 0;
	square_length = solution[1];
	corner_map_pos = solution[0];
	filled_char = md.symbols[2];
	while (square_y < square_length)
	{
		square_x = 0;
		while (square_x < square_length)
		{
			md.contents[corner_map_pos + square_x + md.length * square_y] \
				= filled_char;
			square_x++;
		}
		square_y++;
	}
}

int	is_position_in_map(int map_pos, int length, int square_length)
{
	if (map_pos % length < length - square_length + 1 && map_pos / \
			length < length - square_length + 1)
	{
		return (1);
	}
	return (0);
}
