/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_min.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:16:11 by mcoskune          #+#    #+#             */
/*   Updated: 2024/03/17 22:39:31 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIAL_CASE_MIN_H
#define SPECIAL_CASE_MIN_H

void	ft_mincase_top_col(int *ref_val, int arr[4][4][5]);
void	ft_mincase_bott_col(int *ref_val, int arr[4][4][5], int i);
void	ft_mincase_left_row(int *ref_val, int arr[4][4][5], int i);
void	ft_mincase_right_row(int *ref_val, int arr[4][4][5], int i);

#endif