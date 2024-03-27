/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:45:13 by ssimmons          #+#    #+#             */
/*   Updated: 2024/03/17 22:38:29 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
#define SOLVE_H

#include "chosen_search.h"
#include "equation_elimination.h"
#include "select_unique.h"
#include "guess_last.h"

int	solve(int r[4][4][5], int *ref_val, int max_loops);

#endif