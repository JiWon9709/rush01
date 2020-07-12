/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlee <ing5751@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 17:05:53 by jlee              #+#    #+#             */
/*   Updated: 2020/07/12 17:28:27 by jlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		find_unassigned(int **grid, int *row, int *col)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (grid[i][j] == 0)
			{
				*row = i;
				*col = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

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
			if ((is_valid_row_view_all(grid, row, row_view) &&
						is_valid_col_view_all(grid, col, col_view)))
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
