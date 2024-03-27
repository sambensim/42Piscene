/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:40:11 by eamsalem          #+#    #+#             */
/*   Updated: 2024/03/26 12:27:47 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*dict;

	dict = open_file("numbers.dict");
	if (argc == 2)
	{
		check_input(argv[1], dict);
	}
	else if (argc == 3)
	{
		free(dict);
		dict = open_file(argv[1]);
		check_input(argv[2], dict);
	}
	else
		write(1, "Error: wrong number of arguments\n", 33);
	free(dict);
}
