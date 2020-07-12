/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlee <ing5751@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 17:02:57 by jlee              #+#    #+#             */
/*   Updated: 2020/07/12 17:27:02 by jlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_safe_num(int **grid, int row, int col)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (i != col && grid[row][i] == grid[row][col])
			return (0);
		if (i != row && grid[i][col] == grid[row][col])
			return (0);
		i++;
	}
	return (1);
}

int		is_valid_row_view(int **grid, int row, int **row_view, int inverse)
{
	int i;
	int k;
	int count;
	int current_height;

	i = 0;
	count = 0;
	current_height = 0;
	while (i < 4)
	{
		k = i;
		if (inverse)
			k = 3 - i;
		if (grid[row][k] == 0)
			return (1);
		if (grid[row][k] > current_height)
		{
			current_height = grid[row][k];
			count++;
		}
		i++;
	}
	if (count == row_view[row][inverse])
		return (1);
	return (0);
}

int		is_valid_col_view(int **grid, int col, int **col_view, int inverse)
{
	int i;
	int k;
	int count;
	int current_height;

	i = 0;
	count = 0;
	current_height = 0;
	while (i < 4)
	{
		k = i;
		if (inverse)
			k = 3 - i;
		if (grid[k][col] == 0)
			return (1);
		if (grid[k][col] > current_height)
		{
			current_height = grid[k][col];
			count++;
		}
		i++;
	}
	if (count == col_view[col][inverse])
		return (1);
	return (0);
}

int		is_valid_row_view_all(int **grid, int row, int **row_view)
{
	int is_valid;

	is_valid = is_valid_row_view(grid, row, row_view, 0)
		&& is_valid_row_view(grid, row, row_view, 1);
	return (is_valid);
}

int		is_valid_col_view_all(int **grid, int col, int **col_view)
{
	int is_valid;

	is_valid = is_valid_col_view(grid, col, col_view, 0)
		&& is_valid_col_view(grid, col, col_view, 1);
	return (is_valid);
}
