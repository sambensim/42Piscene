/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chosen_search.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:45:43 by ssimmons          #+#    #+#             */
/*   Updated: 2024/03/17 22:35:07 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef chosen_seach
#define chosen_seach

int	chosen_value(int r[4][4][5], int x, int y);
void	collapse(int r[4][4][5], int x, int y, int value);
void	chosen_search(int r[4][4][5]);


#endif