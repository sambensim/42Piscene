/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:28:09 by mcoskune          #+#    #+#             */
/*   Updated: 2024/03/17 22:38:50 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_case_top_col(int *ref_val, int arr[4][4][5])
{
	int	j;
	int	x;
	int	y;
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (ref_val[i] == 4)
		{
			y = -1;
			x = ref_val[i];
			while (++y < 4)
			{
				j = -1;
				while (arr[x][y][++j] != 0)
				{
					if (arr[x][y][j] != y + 1)
						arr[x][y][j] = 0;
				}
			}
		}
	}
	ft_case_bott_col(ref_val, arr, i);
}

void	ft_case_bott_col(int *ref_val, int arr[4][4][5], int i)
{
	int	j;
	int	x;
	int	y;

	while (4 <= i && i < 8)
	{
		if (ref_val[i] == 4)
		{
			y = 3;
			x = i - 4;
			while (y >= 0)
			{
				j = 3;
				while (arr[x][y][j] != 0)
				{
					if (arr[x][y][j] != 4 - y)
						arr[x][y][j] = 0;
					j++;
				}
				y--;
			}
		}
		i++;
	}
	ft_case_left_row(ref_val, arr, i);
}

void	ft_case_left_row(int *ref_val, int arr[4][4][5], int i)
{
	int	j;
	int	x;
	int	y;

	while (8 <= i && i < 12)
	{
		if (ref_val[i] == 4)
		{
			y = i - 8;
			x = 0;
			while (x < 4)
			{
				j = 0;
				while (arr[x][y][j] != 0)
				{
					if (arr[x][y][j] != x + 1)
						arr[x][y][j] = 0;
					j++;
				}
				x++;
			}
		}
		i++;
	}
	ft_case_right_row(ref_val, arr, i);
}

void	ft_case_right_row(int *ref_val, int arr[4][4][5], int i)
{
	int	j;
	int	x;
	int	y;

	while (12 <= i && i < 16)
	{
		if (ref_val[i] == 4)
		{
			y = i - 12;
			x = 3;
			while (x >= 0)
			{
				j = 0;
				while (arr[x][y][j] != 0)
				{
					if (arr[x][y][j] != 4 - x)
						arr[x][y][j] = 0;
					j++;
				}
				x--;
			}
		}
		i++;
	}
}
