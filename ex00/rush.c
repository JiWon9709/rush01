/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlee <ing5751@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:59:23 by jlee              #+#    #+#             */
/*   Updated: 2020/07/12 14:54:45 by jlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

int		is_valid_view(int **grid, int row, int col, int **row_view, int **col_view)
{
	int is_valid;

	is_valid = is_valid_row_view(grid, row, row_view, 0)
		&& is_valid_row_view(grid, row, row_view, 1)
		&& is_valid_col_view(grid, col, col_view, 0)
		&& is_valid_col_view(grid, col, col_view, 1);
	return (is_valid);
}

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

void	initialize_grid(int **grid)
{
	int row;
	int col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}

void	print_grid(int **grid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = '0' + grid[i][j];
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		check_input_error(int argc, char *argv[])
{
	int i;

	i = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i])
	{
		if (i == 0 || i % 2 == 0)
		{
			if (!(argv[1][i] >= '1' && argv[1][i] <= '4'))
				return (0);
		}
		else
		{
			if (argv[1][i] != ' ')
				return (0);
		}
		i++;
	}
	i = 0;
	while (argv[1][i])
		i++;
	if (i != 31)
		return (0);
	return (1);
}

void	input_to_array(char *argv[], int **col_view, int **row_view)
{
	int i;
	int a;
	int b;
	int c;
	int d;

	i = 0;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	while (i < 4)
	{
		a = i * 2;
		b = (i + 4) * 2;
		c = (i + 8) * 2;
		d = (i + 12) * 2;
		col_view[i][0] = argv[1][a] - '0';
		col_view[i][1] = argv[1][b] - '0';
		row_view[i][0] = argv[1][c] - '0';
		row_view[i][1] = argv[1][d] - '0';
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int	i;
	int	*grid[4];
	int	**row_view;
	int	**col_view;

	i = 0;
	while (i < 4)
	{
		grid[i] = (int*)malloc(sizeof(int) * 4);
		i++;
	}
	i = 0;
	row_view = (int**)malloc(sizeof(int*) * 4);
	col_view = (int**)malloc(sizeof(int*) * 4);
	while (i < 4)
	{
		row_view[i] = (int*)malloc(sizeof(int) * 2);
		col_view[i] = (int*)malloc(sizeof(int) * 2);
		i++;
	}
	if (!check_input_error(argc, argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	input_to_array(argv, row_view, col_view);
	initialize_grid(grid);
	if (solve(grid, row_view, col_view))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	i = 0;
	while (i < 4)
	{
		free(row_view[i]);
		free(col_view[i]);
		i++;
	}
	free(row_view);
	free(col_view);
	i = 0;
	while (i < 4)
	{
		free(grid[i]);
		i++;
	}
	return (0);
}
