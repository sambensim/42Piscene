/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:57:39 by ssimmons          #+#    #+#             */
/*   Updated: 2024/03/24 23:31:22 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

char	*ft_strcpy(char *dest, char *src);

char	*ft_strcat(char *dest, char *src);

void	print_value(char *dict, int i);

int		ft_strlen(char *str);

int		get_period(int len);

int		not_zero(char digit);

int		search_period(int period, char *dict);

void	add_value(int value, int *ptr);

char	*buff_zeros(char *arr, char *zero_buff, int len);

int		search_tens(char ten, char digit, char *dict);

int		search(char *dict, char *nb);

void	parse_array(int period, char *arr, char *dict);

int		char_search(char *dict, char c);

int		ft_strncmp(char *s1, char *s2, unsigned int n);

void	ft_putchar(char c);

int		is_skipped(char c);

int		skip(char *dict, int i);

int		find_line(char *dict, char *nb);

void	write_number(char *arr, char *dict);

char	*open_file(const char *filename);

void	add_value(int value, int *ptr);

void	parse_arr(int period, char *arr, char *dict, int *words);

char	*buff_zeros(char *arr, char *zero_buff, int len);

void	write_number(char *arr, char *dict);

int		check_file_errors(int fd, int bytes_read);

int		check_dict_error(int *words);

int		atoi_check(char *input);

void	check_input(char *input, char *dict);

#endif 
