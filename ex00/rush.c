/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 17:23:56 by jlee              #+#    #+#             */
/*   Updated: 2020/07/11 17:52:17 by jlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		is_valid_row_view(int **grid, int row, int **row_view, int inverse)
{
	int i;
	int k;
	int count;
	int current_height;

	i = 0;
	while (i < 4)
	{
		k = i;
		if (inverse)
			k = 3 - i;
		if (grid[row][k] == 0)
			return 1;

	if (grid[row][k] > current_height)
	{
		current_height = grid[row][k];
		count++;
	}
	i++;
	}

	if(count == row_view[row][inverse])
		return 1;
	return 0;
}

int		is_unassigned(int **grid, int *row, int *col)
{

}

int		is_valid_row_col()
{

}

int		process(int **grid, int **row_view, int **col_view)
{
	int val;
	int *row;
	int *col;

	val = 1;
	if (!is_unassigned)
		return 1;
	while (val <= 4)
	{
		grid[row][col] = val;
		if (is_valid_row_col)
		{
			if (is_valid_row_view && is_valid_col_view)
			{
				if (process)
					return 1;
			}
		}
		grid[row][col] = 0;
		val++;
	}
	return 0;
}

int		main()
{
	int grid[4][4];
	int i;
	int j;
	int count;
	int **row_view;
	int **col_view;

	process(int **grid, int **row_view, int **col_view);
	print_grid(**grid);
	return 0;
}
