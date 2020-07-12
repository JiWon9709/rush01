/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlee <ing5751@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 17:05:53 by jlee              #+#    #+#             */
/*   Updated: 2020/07/12 17:06:16 by jlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		solve(int **grid, int **row_view, int **col_view)
{
	int row;
	int col;
	int val;

	val = 1;
	if (!find_unassigned(grid, &row, &col))
		return (1);
	while (val <= 4)
	{
		grid[row][col] = val;
		if (is_safe_num(grid, row, col))
		{
			if (is_valid_view(grid, row, col, row_view, col_view))
			{
				if (solve(grid, row_view, col_view))
					return (1);
			}
		}
		grid[row][col] = 0;
		val++;
	}
	return (0);
}
