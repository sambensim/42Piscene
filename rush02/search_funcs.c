/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:01:39 by ssimmons          #+#    #+#             */
/*   Updated: 2024/03/26 12:30:22 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>
#include <stdio.h>

int	search(char *dict, char *nb)
{
	int	i;

	printf("%s",nb);
	i = find_line(dict, nb);
	if (i == -1)
		return (-1);
	while (dict[i] != ':' && dict[i] != '\0' && dict[i] != '\n')
		i++;
	if (dict[i] != ':')
		return (-1);
	return (i);
}

int	char_search(char *dict, char c)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	return (search(dict, str));
}

int	search_period(int period, char *dict)
{
	char	str[50];
	int		i;

	i = (period - 1) * 3;
	ft_strcpy(str, "1");
	while (i > 0)
	{
		ft_strcat(str, "0");
		i--;
	}
	return (search(dict, str));
}

int	search_tens(char ten, char digit, char *dict)
{
	char	str[3];

	str[0] = ten;
	str[1] = digit;
	str[2] = '\0';
	return (search(dict, str));
}

int	find_line(char *dict, char *nb)
{
	int	i;
	int	found;
	int	len;

	i = 0;
	found = 0;
	len = ft_strlen(nb);
	while (!found && dict[i])
	{
		i = skip(dict, i);
		if (dict[i] == ':')
		{
			while (dict[i] && dict[i - 1] != '\n')
				i++;
		}
		if (ft_strncmp(&dict[i], nb, len) == 0 && \
			(is_skipped(dict[i + len]) || dict[i + len] == ':'))
			found = 1;
		i++;
	}
	if (found)
		return (i);
	return (-1);
}
