/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guess_last.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:53:04 by ssimmons          #+#    #+#             */
/*   Updated: 2024/03/17 22:36:45 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUESS_LAST_H
#define GUESS_LAST_H

#include "chosen_search.h"
#include "select_unique.h"
#include "solve.h"

int	check_status(int r[4][4][5]);
int	***dup_array(int r[4][4][5], int dup[4][4][5]);
void	set_value(int r[4][4][5], int x, int y, int guess);
int try_solve(int r[4][4][5], int x, int y, int guess, int max_loops);
int	guess_last(int r[4][4][5]);

#endif