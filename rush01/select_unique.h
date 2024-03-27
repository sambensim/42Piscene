/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_unique.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:45:37 by ssimmons          #+#    #+#             */
/*   Updated: 2024/03/17 22:38:16 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_UNIQUE_H
#define SELECT_UNIQUE_H

void	select_value(int r[4][4][5], int x, int y, int value);
int	revalue_unique(int cell_value, int unique, int new_value);
void	select_unique_onrows(int r[4][4][5]);
void	select_unique_oncols(int r[4][4][5]);
void	select_unique(int r[4][4][5]);

#endif