/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:59:47 by ssimmons          #+#    #+#             */
/*   Updated: 2024/03/24 21:35:04 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	get_period(int len)
{
	if (len % 3 == 0)
		return (len / 3);
	else
		return ((len / 3) + 1);
}

int	not_zero(char digit)
{
	if (digit == '0')
		return (0);
	else
		return (1);
}

int	is_skipped(char c)
{
	if ((c == ' ' || c == '\t') \
	|| (c == '\v' || c == '\f' || c == '\r'))
		return (1);
	return (0);
}

int	skip(char *dict, int i)
{
	while (is_skipped(dict[i]))
		i++;
	return (i);
}

void	print_value(char *dict, int i)
{
	i = skip(dict, i + 1);
	while (dict[i] && dict[i] != '\n')
	{
		if (is_skipped(dict[i]))
		{
			if (dict[skip(dict, i)] != '\n')
				ft_putchar(' ');
			i = skip(dict, i);
		}
		else
			ft_putchar(dict[i++]);
	}
}
