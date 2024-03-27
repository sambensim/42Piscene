/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:28:54 by mcoskune          #+#    #+#             */
/*   Updated: 2024/03/17 22:39:21 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_mincase_top_col(int *ref_val, int arr[4][4][5])
{
	int	j;
	int	x;
	int	y;
	int	i;

	while (i < 4)
	{
		if (ref_val[i] == 1)
		{
			y = 0;
			x = ref_val[i];
			j = 0;
			while (arr[x][y][j] != 0)
			{
				if (arr[x][y][j] != 4)
					arr[x][y][j] = 0;
				j++;
			}
		}
		i++;
	}
	ft_mincase_bott_col(ref_val, arr, i);
}

void	ft_mincase_bott_col(int *ref_val, int arr[4][4][5], int i)
{
	int	j;
	int	x;
	int	y;

	while (4 <= i && i < 8)
	{
		if (ref_val[i] == 1)
		{
			y = 3;
			x = ref_val[i] -4;
			j = 0;
			while (arr[x][y][j] != 0)
			{
				if (arr[x][y][j] != 4)
					arr[x][y][j] = 0;
				j++;
			}
		}
		i++;
	}
	ft_mincase_left_row(ref_val, arr, i);
}

void	ft_mincase_left_row(int *ref_val, int arr[4][4][5], int i)
{
	int	j;
	int	x;
	int	y;

	while (8 <= i && i < 12)
	{
		if (ref_val[i] == 1)
		{
			y = ref_val[i] - 8;
			x = 0;
			j = 0;
			while (arr[x][y][j] != 0)
			{
				if (arr[x][y][j] != 4)
					arr[x][y][j] = 0;
				j++;
			}
		}
		i++;
	}
	ft_mincase_right_row(ref_val, arr, i);
}

void	ft_mincase_right_row(int *ref_val, int arr[4][4][5], int i)
{
	int	j;
	int	x;
	int	y;

	while (12 <= i && i < 16)
	{
		if (ref_val[i] == 1)
		{
			y = ref_val[i] - 12;
			x = 3;
			j = 0;
			while (arr[x][y][j] != 0)
			{
				if (arr[x][y][j] != 4)
					arr[x][y][j] = 0;
				j++;
			}
		}
		i++;
	}
}
