/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_elimination.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:20:31 by mcoskune          #+#    #+#             */
/*   Updated: 2024/03/17 22:34:37 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_x(int i, int j)
{
	if (i < 4 * 2)
		return (i % 4);
	if (i < 4 * 3)
		return (j);
	return ((4 - 1) - j);
}

int	get_y(int i, int j)
{
	if (i < 4)
		return (j);
	if (i < 4 * 2)
		return ((4 - 1) - j);
	return (i % 4);
}

void	remove_above(int x, int y, int value, int r[4][4][5])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (r[x][y][i] >= value)
			r[x][y][i] = 0;
	}
}

void	equation_elimination(int r[4][4][5], int *ref_val)
{
	int	i;
	int	j;
	int	cost;

	while (i < 4 * 4)
	{
		j = 0;
		cost = (4 + 2 - ref_val[i]);
		while (j < 4)
		{
			remove_above(get_x(i, j), get_y(i, j), cost + j, r);
			j++;
		}
	}
}
