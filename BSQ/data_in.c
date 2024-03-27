/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:51:55 by ssimmons          #+#    #+#             */
/*   Updated: 2024/03/27 19:06:05 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "biggest_square.h"

char	*read_map_file(char *path)
{
	int		bytes_to_read;
	int		bytes_read;
	char	*destination;

	bytes_to_read = 1200000 * sizeof(char);
	destination = (char *) malloc(bytes_to_read);
	if (!destination)
		exit(-1);
	if (!destination)
		return (destination);
	bytes_read = read(open(path, O_RDONLY), destination, bytes_to_read);
	destination[bytes_read] = '\0';
	return (destination);
}

int	is_header_valid(char *map_raw)
{
	int	offset;
	int	count;
	int	i;

	offset = 0;
	count = 0;
	if (!is_number(map_raw[0]) || read_map_length(map_raw) < 1)
		return (0);
	while (map_raw[offset] != '\n')
		offset++;
	offset -= 3;
	while (map_raw[offset + count] != '\n')
	{
		i = 1;
		while (map_raw[offset + i + count] != '\n')
		{
			if (map_raw[offset + i + count] == map_raw[offset + count])
				return (0);
			i++;
		}
		count++;
	}
	if (count != 3)
		return (0);
	return (offset + count + 1);
}

int	is_map_valid(char *map_raw, struct s_mapdata md)
{
	int	offset;
	int	count;
	int	height;

	offset = is_header_valid(map_raw);
	count = -1;
	height = 0;
	md.max_square_length = 0;
	while (map_raw[offset + height + ++count])
	{
		if (map_raw[offset + height + count] == md.symbols[0])
			md.max_square_length++;
		else if (map_raw[offset + height + count] == '\n')
		{
			if (count != md.length)
				return (0);
			height += count;
			count = 0;
			offset++;
		}
		else if (map_raw[offset + height + count] != md.symbols[1])
			return (0);
	}
	return (md.max_square_length * ((count + height) / md.length == md.length));
}

char	*take_symbols(char *map)
{
	int		i;
	char	*symbols;

	i = 0;
	while (map[i] != '\n')
	{
		i++;
	}
	symbols = (char *) malloc(sizeof(char) * 3);
	symbols[0] = map[i - 3];
	symbols[1] = map[i - 2];
	symbols[2] = map[i - 1];
	return (symbols);
}

char	*clean_map(char *map)
{
	int		length;
	int		i;
	int		map_pos;
	char	*cleaned_map;

	length = read_map_length(map);
	cleaned_map = (char *) malloc(sizeof(char) * (length * length + 1));
	i = 0;
	map_pos = 0;
	while (map[map_pos] != '\n')
	{
		map_pos++;
	}
	while (map[map_pos])
	{
		if (map[map_pos] != '\n')
		{
			cleaned_map[i] = map[map_pos];
			i++;
		}
		map_pos++;
	}
	return (cleaned_map);
}
