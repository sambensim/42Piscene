/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:52:01 by ssimmons          #+#    #+#             */
/*   Updated: 2024/03/27 19:06:10 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "biggest_square.h"
#define BUFFER_SIZE 100

char	*read_from_stdin(char *buffer, int buffer_size)
{
	int	bytes_read;
	int	tbr;

	bytes_read = 0;
	tbr = 0;
	while (tbr < buffer_size - 1)
	{
		bytes_read = read(STDIN_FILENO, buffer + tbr, 1);
		if (bytes_read < 0)
		{
			break ;
		}
		else if (bytes_read == 0 || buffer[tbr] == '\n')
			break ;
		tbr += bytes_read;
	}
	buffer[tbr] = '\0';
	return (buffer);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	buffer[BUFFER_SIZE];

	i = 0;
	if (argc == 1)
	{
		read_from_stdin(buffer, BUFFER_SIZE);
		biggest_square_wrapper(buffer);
	}
	else
	{
		while (++i < argc)
		{
			biggest_square_wrapper(argv[i]);
			ft_putchar('\n');
			if (i < argc - 1)
				ft_putchar('\n');
		}
	}
}
