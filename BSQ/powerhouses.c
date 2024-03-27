/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerhouses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:52:04 by ssimmons          #+#    #+#             */
/*   Updated: 2024/03/27 18:53:36 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "biggest_square.h"
#include <stdio.h>

int	*find_square_brute_force(struct s_mapdata md)
{
	int	map_pos;
	int	test_length;
	int	*answer;

	answer = (int *) malloc(sizeof(int) * 2);
	test_length = md.max_square_length;
	while (test_length > 0)
	{
		map_pos = 0;
		while (map_pos < (md.length * md.length))
		{
			if (is_position_in_map(map_pos, md.length, test_length) \
				&& is_square_valid(md, map_pos, test_length))
			{
				answer[0] = map_pos;
				answer[1] = test_length;
				return (answer);
			}
			map_pos++;
		}
		test_length--;
	}
	return (0);
}

void	draw_solved_map(struct s_mapdata md, int *solution)
{
	int	map_pos;

	fill_square(md, solution);
	map_pos = 0;
	while (map_pos < md.length * md.length)
	{
		if (map_pos % md.length == 0 && map_pos != 0)
		{
			ft_putchar('\n');
		}
		ft_putchar(md.contents[map_pos]);
		map_pos++;
	}
}

void	free_them(char *map_raw, struct s_mapdata md)
{
	free(map_raw);
	free(md.contents);
}

int	biggest_square_wrapper(char *filepath)
{
	int					*solution;
	char				*map_raw;
	struct s_mapdata	md;

	map_raw = read_map_file(filepath);
	if (!is_header_valid(map_raw))
	{
		free(map_raw);
		ft_putstr("map error");
		return (0);
	}
	md.symbols = take_symbols(map_raw);
	md.length = read_map_length(map_raw);
	md.max_square_length = ft_sqrt(is_map_valid(map_raw, md));
	if (!md.max_square_length)
	{
		free_them(map_raw, md);
		ft_putstr("map error");
		return (0);
	}
	md.contents = clean_map(map_raw);
	solution = find_square_brute_force(md);
	draw_solved_map(md, solution);
	free_them(map_raw, md);
	return (1);
}
