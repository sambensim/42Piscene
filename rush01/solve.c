/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssimmons <sambensim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:27:29 by mcoskune          #+#    #+#             */
/*   Updated: 2024/03/17 22:38:21 by ssimmons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	solve(int r[4][4][5], int *ref_val, int max_loops)
{
	int	status;
	int	loop_number;

	loop_number = 0;
	equation_elimination(r, ref_val);
	while (++loop_number <= max_loops && !status)
	{
		chosen_search(r);
		select_unique(r);
		status = check_status(r);
	}
	status = guess_last(r);
	if (status == 0)
		return (0);
	else
		return (1);
}
