/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_elimination.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:45:40 by ssimmons          #+#    #+#             */
/*   Updated: 2024/03/17 22:35:18 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUATION_ELIMINATION_H
#define EQUATION_ELIMINATION_H

int	get_x(int i, int j);
int	get_y(int i, int j);
void	remove_above(int x, int y, int value, int r[4][4][5]);
void	equation_elimination(int r[4][4][5], int *ref_val);

#endif