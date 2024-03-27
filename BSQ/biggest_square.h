/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_square.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:51:49 by ssimmons          #+#    #+#             */
/*   Updated: 2024/03/27 18:41:06 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGGEST_SQUARE_H
# define BIGGEST_SQUARE_H

struct	s_mapdata
{
	char	*contents;
	char	*symbols;
	int		length;
	int		max_square_length;
};

void	ft_putchar(char character);

int		is_number(char character);

int		read_map_length(char *map);

int		find_map_length(char *map);

void	ft_putstr(char *str);

int		is_position_in_map(int map_pos, int length, int square_length);

char	*read_map_file(char *path);

int		is_header_valid(char *map_raw);

int		is_map_valid(char *map_raw, struct s_mapdata md);

char	*take_symbols(char *map);

char	*clean_map(char *map);

int		calc_max_positions_root(int length, int square_length);

int		ft_sqrt(int nb);

int		is_square_valid(struct s_mapdata md, int corner_map_pos, \
	int square_length);

void	fill_square(struct s_mapdata md, int *solution);

int		*find_square_brute_force(struct s_mapdata md);

void	draw_solved_map(struct s_mapdata md, int *solution);

int		biggest_square_wrapper(char *filepath);

#endif