/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_max.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:32:49 by mcoskune          #+#    #+#             */
/*   Updated: 2024/03/17 22:39:05 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIAL_CASE_MAX_H
#define SPECIAL_CASE_MAX_H

void	ft_case_top_col(int *ref_val, int arr[4][4][5]);
void	ft_case_bott_col(int *ref_val, int arr[4][4][5], int i);
void	ft_case_left_row(int *ref_val, int arr[4][4][5], int i);
void	ft_case_right_row(int *ref_val, int arr[4][4][5], int i);

#endif