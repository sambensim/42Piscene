/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:42:57 by mcoskune          #+#    #+#             */
/*   Updated: 2024/03/17 22:44:50 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include "solve.h"
#include "populate_matrix.h"
#include "ft_print.h"
#include "special_case_max.h"
#include "special_case_min.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	ref_val[16];
	int	arr[4][4][5];

	printf("%s", "test");
	if (argc == 2)
	{
		i = 0;
		while (i < 31)
		{
			ref_val[i/2] = argv[1][i]-'0';
			i+=2;
		}
		ft_populate_matrix(arr);
		ft_case_top_col(ref_val, arr);
		ft_mincase_top_col(ref_val, arr);
		solve(arr, ref_val, 16);
	}
}
