/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_unique.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:26:06 by mcoskune          #+#    #+#             */
/*   Updated: 2024/03/17 22:37:57 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	select_value(int r[4][4][5], int x, int y, int value)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i != value - 1)
			r[x][y][i] = 0;
	}
}

int	revalue_unique(int cell_value, int unique, int new_value)
{
	if (cell_value)
	{
		if (unique == -1)
			return (new_value);
		return (-2);
	}
	return (-1);
}

void	select_unique_onrows(int r[4][4][5])
{
	int	x;
	int	y;
	int	i;
	int	unique;

	y = -1;
	while (++y < 4)
	{
		i = -1;
		while (++i < 4)
		{
			unique = -1;
			x = -1;
			while (++x < 4)
				unique = revalue_unique(r[x][y][i], unique, x);
			if (unique > -1)
				select_value(r, unique, y, i);
		}
	}
}

void	select_unique_oncols(int r[4][4][5])
{
	int	x;
	int	y;
	int	i;
	int	unique;

	x = -1;
	while (++x < 4)
	{
		i = -1;
		while (++i < 4)
		{
			unique = -1;
			y = -1;
			while (++y < 4)
				unique = revalue_unique(r[x][y][i], unique, y);
			if (unique > -1)
				select_value(r, x, unique, i);
		}
	}
}

void	select_unique(int r[4][4][5])
{
	select_unique_onrows(r);
	select_unique_oncols(r);
}
