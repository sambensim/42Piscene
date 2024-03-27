/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:21:48 by eamsalem          #+#    #+#             */
/*   Updated: 2024/03/24 23:21:51 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*open_file(const char *filename)
{
	int		fd;
	int		bytes_read;
	int		i;
	char	*buff;
	int		buffer_size;

	buffer_size = 24000;
	fd = open(filename, O_RDONLY);
	bytes_read = buffer_size;
	buff = (char *)malloc(buffer_size);
	while (bytes_read == buffer_size)
	{
		free(buff);
		buff = (char *)malloc(buffer_size);
		buffer_size += 100;
		bytes_read = read(fd, buff, buffer_size);
	}
	if (check_file_errors(fd, bytes_read))
		buff[bytes_read] = '\0';
	close (fd);
	return (buff);
}

void	add_value(int value, int *ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != -2)
		i++;
	ptr[i] = value;
	ptr[i + 1] = -2;
}

void	parse_arr(int period, char *arr, char *dict, int *words)
{
	int	i;

	while (period > 0)
	{
		i = ft_strlen(arr) - (period * 3);
		if (not_zero(arr[i]))
		{
			add_value(char_search(dict, arr[i]), words);
			add_value(search(dict, "100"), words);
		}
		if (arr[i + 1] == '1')
			add_value(search_tens(arr[i + 1], arr[i + 2], dict), words);
		else if (not_zero(arr[i + 1]))
		{
			add_value(search_tens(arr[i + 1], '0', dict), words);
			if (not_zero(arr[i + 2]))
				add_value(char_search(dict, arr[i + 2]), words);
		}
		else if (not_zero(arr[i + 2]))
			add_value(char_search(dict, arr[i + 2]), words);
		if (period > 1 && (not_zero(arr[i]) || \
		not_zero(arr[i + 1]) || not_zero(arr[i + 2])))
			add_value(search_period(period, dict), words);
		period--;
	}
}

char	*buff_zeros(char *arr, char *zero_buff, int len)
{
	zero_buff[0] = '\0';
	if (len % 3 == 1)
	{
		zero_buff[0] = '0';
		zero_buff[1] = '0';
		zero_buff[2] = '\0';
	}
	else if (len % 3 == 2)
	{
		zero_buff[0] = '0';
		zero_buff[1] = '\0';
	}
	ft_strcat(zero_buff, arr);
	return (zero_buff);
}

void	write_number(char *arr, char *dict)
{
	int		period;
	int		len;
	int		words[72];
	int		i;
	char	zero_buff[50];

	words[0] = -2;
	len = ft_strlen(arr);
	period = get_period(len);
	arr = buff_zeros(arr, zero_buff, len);
	parse_arr(period, arr, dict, words);
	i = 0;
	if (check_dict_error(words))
		return ;
	else
	{
		while (words[i + 1] != -2)
		{
			print_value(dict, words[i++]);
			write(1, " ", 1);
		}
	}
	print_value(dict, words[i]);
	write(1, "\n", 1);
}
