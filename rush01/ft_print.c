/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:22:00 by mcoskune          #+#    #+#             */
/*   Updated: 2024/03/17 22:32:58 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print(int arr[4][4][5])
{
	int	x;
	int	y;
	int	i;

	y = -1;
	while (++y < 3)
	{
		x = -1;
		while (++x < 3)
		{
			i = -1;
			while (++i < 5)
			{
				if (arr[x][y][i] != 0)
				{
					ft_write(arr[x][y][i]);
					if (i < 4)
						write (1, " ", 1);
				}
			}
		}
		write (1, "\n", 1);
	}
}

void	ft_write(char c)
{
	write (1, &c, 1);
}
