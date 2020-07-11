/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlee <ing5751@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:59:23 by jlee              #+#    #+#             */
/*   Updated: 2020/07/11 22:35:50 by jlee             ###   ########.fr       */
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
			return 1;

	if (grid[k][col] > current_height)
	{
		current_height = grid[k][col];
		count++;
	}
	i++;
	}

	if(count == col_view[col][inverse])
		return 1;
	return 0;
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

int		is_unassigned(int **grid, int *row, int *col)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if(grid[i][j] == 0)
			{
				*row = i;
				*col = j;
				return 1;
			}
			j++;
		}
		i++;
	}
	return 0;
}

int		is_valid_row_col(int **grid, int row, int col)
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

int		process(int **grid, int **row_view, int **col_view)
{
	int val;
	int row;
	int col;

	val = 1;
	if (!is_unassigned(grid, &row, &col))
		return 1;
	while (val <= 4)
	{
		grid[row][col] = val;
		if (is_valid_row_col(grid, row, col))
		{
			if (is_valid_view(grid, row, col, row_view, col_view))
			{
				if (process(grid, row_view, col_view))
					return 1;
			}
		}
		grid[row][col] = 0;
		val++;
	}
	return 0;
}

void		initialize_grid(int **grid)
{
	int i;
    int j;
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            grid[i][j] = 0;
            j++;
        }
        i++;
    }
}

void    print_grid(int **grid)
{
    char    g[4][4];
    int     i;
    int     j;
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            g[i][j] = '0' + grid[i][j];
            write(1, &g[i][j], 1);
			if (j < 3)
				write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

int		main(int argc, char *argv[])
{
	int i;
	int *grid[4];
	int** row_view;
	int** col_view;

	if (argc != 2)
		return -1;
	
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
		
	col_view[0][0] = argv[1][0] - '0';
	col_view[1][0] = argv[1][1] - '0';
	col_view[2][0] = argv[1][2] - '0';
	col_view[3][0] = argv[1][3] - '0';
	col_view[0][1] = argv[1][4] - '0';
	col_view[1][1] = argv[1][5] - '0';
	col_view[2][1] = argv[1][6] - '0';
	col_view[3][1] = argv[1][7] - '0';
	row_view[0][0] = argv[1][8] - '0';
	row_view[1][0] = argv[1][9] - '0';
	row_view[2][0] = argv[1][10] - '0';
	row_view[3][0] = argv[1][11] - '0';
	row_view[0][1] = argv[1][12] - '0';
	row_view[1][1] = argv[1][13] - '0';
	row_view[2][1] = argv[1][14] - '0';
	row_view[3][1] = argv[1][15] - '0';

	initialize_grid(grid);
	process(grid, row_view, col_view);
	print_grid(grid);
	i = 0;
	while (i < 4)
	{
		free(grid[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		free(row_view[i]);
		free(col_view[i]);
	i++;
	}
	return 0;
}
