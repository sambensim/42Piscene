/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:25:27 by eamsalem          #+#    #+#             */
/*   Updated: 2024/03/26 12:29:18 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <unistd.h>

int	check_file_errors(int fd, int bytes_read)
{
	if (fd == -1)
	{
		write(1, "Error Opening File\n", 20);
		return (0);
	}
	if (bytes_read == -1)
	{
		write (1, "Error Reading File\n", 19);
		return (0);
	}
	return (1);
}

int	check_dict_error(int *words)
{
	int	i;

	i = 0;
	while (words[i] != -2)
	{
		if (words[i] == -1)
		{
			write(1, "Dict Error\n", 11);
			return (1);
		}
		i++;
	}
	return (0);
}

int	atoi_check(char *input)
{
	int		i;
	int		j;
	int		sign;
	char	number[42];

	i = 0;
	while (input[i] >= 9 && input[i] <= 13 || input[i] == 32)
		i++;
	sign = 1;
	while (input[i] == '-' || input[i] == '+')
	{
		if (input[i] == '-')
			sign *= (-1);
		i++;
	}
	j = 0;
	if (sign == -1)
		return (0);
	while (input[i] >= '0' && input[i] <= '9')
		number[j++] = input[i++];
	ft_strcpy(input, number);
	return (1);
}

void	check_input(char *input, char *dict)
{
	if (!atoi_check(input))
		write(1, "Error\n", 6);
	else if (input[0] == '\0')
		write(1, "Error\n", 6);
	else if (!ft_strncmp(input, "0", 1))
		print_value(dict, char_search(dict, '0'));
	else
		write_number(input, dict);
}
