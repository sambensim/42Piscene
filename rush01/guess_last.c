/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guess_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:23:21 by mcoskune          #+#    #+#             */
/*   Updated: 2024/03/17 22:36:10 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Status 0 == unsolved, status 1 == only 1s and 2s, status 2 == solved
int	check_status(int r[4][4][5])
{
	int	status;
	int	x;
	int	y;
	int	i;

	y = -1;
	status = 2;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			i = -1;
			while (++i < 4)
			{
				if (r[x][y][i] >= 3)
					return (0);
				if (r[x][y][i] == 1 || r[x][y][i] == 2)
					status = 1;
			}
		}
	}
	return (status);
}

int ***dup_array(int r[4][4][5], int dup[4][4][5])
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			i = 0;
			while (i < 4)
			{
				dup[x][y][i] = r[x][y][i];
				i++;
			}
			x++;
		}
		y++;
	}
	return (dup);
}

void	set_value(int r[4][4][5], int x, int y, int guess)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (i != guess - 1)
			r[x][y][i] = 0;
		i++;
	}
}

int try_solve(int r[4][4][5], int x, int y, int guess, int max_loops)
{
	int	status;
	int	loop_number;

	set_value(r, x, y, guess);
	while (++loop_number <= max_loops)
		{
			chosen_search(r);
			select_unique(r);
			status = check_status(r);
		}
	return (status / 2);
}

int	guess_last(int r[4][4][5])
{
	int	guess;
	int	x;
	int	y;
	int	i;
	int dup[4][4][5];

	guess = 1;
	while (guess <= 3)
	{
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if (r[x][y][guess - 1] && !chosen_value(r, x, y))
				{
					if (try_solve(dup_array(r, dup), x, y, guess, 16))
					{
						try_solve(r, x, y, guess, 16);
						return (1);
					}
				}
				x++;
			}
			y++;
		}
		guess++;
	}
	return (0);
}
