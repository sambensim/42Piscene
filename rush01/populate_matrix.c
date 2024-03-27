/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:25:10 by mcoskune          #+#    #+#             */
/*   Updated: 2024/03/17 22:33:32 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_populate_matrix(int arr[4][4][5])
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (x < 4)
	{
		while (y < 4)
		{
			while (i < 5)
			{
				if (i < 4)
					arr[x][y][i] = i+1;
				else
					arr[x][y][i] = 0;
				i++;
			}
			y++;
		}
		x++;
	}
}
