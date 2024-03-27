/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chosen_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:18:56 by mcoskune          #+#    #+#             */
/*   Updated: 2024/03/17 22:34:26 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	chosen_value(int r[4][4][5], int x, int y)
{
	int	i;
	int	out_index;

	out_index = 0;
	while (i < 4)
	{
		if (r[x][y][i])
		{
			if (!out_index)
				out_index = r[x][y][i];
			else
				return (0);
		}
	}
	return (out_index);
}

void	collapse(int r[4][4][5], int x, int y, int value)
{
	int	xx;
	int	yy;

	xx = 0;
	while (xx < 4)
	{
		if (xx != x)
			r[xx][y][value - 1] = 0;
		xx++;
	}
	yy = 0;
	while (yy < 4)
	{
		if (yy != y)
			r[x][yy][value - 1] = 0;
		yy++;
	}
}

void	chosen_search(int r[4][4][5])
{
	int	x;
	int	y;
	int	value;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			value = chosen_value(r, x, y);
			if (value)
				collapse(r, x, y, value);
			x++;
		}
		y++;
	}
}
