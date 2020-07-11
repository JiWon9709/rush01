/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 17:23:56 by jlee              #+#    #+#             */
/*   Updated: 2020/07/11 21:45:37 by jlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int *g_grid[4];

int		is_valid_row_view(int row, int **row_view, int inverse)
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
		if (g_grid[row][k] == 0)
			return 1;

	if (g_grid[row][k] > current_height)
	{
		current_height = g_grid[row][k];
		count++;
	}
	i++;
	}

	if(count == row_view[row][inverse])
		return 1;
	return 0;
}

int		is_valid_col_view(int col, int **col_view, int inverse)
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
		if (g_grid[k][col] == 0)
			return 1;

	if (g_grid[k][col] > current_height)
	{
		current_height = g_grid[k][col];
		count++;
	}
	i++;
	}

	if(count == col_view[col][inverse])
		return 1;
	return 0;
}

int		is_valid_view(int row, int col, int **row_view, int **col_view)
{
	int is_valid;

	is_valid = is_valid_row_view(row, row_view, 0)
		&& is_valid_row_view(row, row_view, 1)
		&& is_valid_col_view(col, col_view, 0)
		&& is_valid_col_view(col, col_view, 1);
	return (is_valid);
}

int		is_unassigned(int *row, int *col)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if(g_grid[i][j] == 0)
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

int		is_valid_row_col(int row, int col)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (i != col && g_grid[row][i] == g_grid[row][col])
			return (0);
		if (i != row && g_grid[i][col] == g_grid[row][col])
			return (0);
		i++;
	}
	return (1);
}

int		process(int **row_view, int **col_view)
{
	int val;
	int row;
	int col;

	val = 1;
	if (!is_unassigned(&row, &col))
		return 1;
	while (val <= 4)
	{
		g_grid[row][col] = val;
		if (is_valid_row_col(row, col))
		{
			if (is_valid_view(row, col, row_view, col_view))
			{
				if (process(row_view, col_view))
					return 1;
			}
		}
		g_grid[row][col] = 0;
		val++;
	}
	return 0;
}

void		initialize_g_grid()
{
	int i;
    int j;
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            g_grid[i][j] = 0;
            j++;
        }
        i++;
    }
}

void    print_g_grid()
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
            g[i][j] = '0' + g_grid[i][j];
            write(1, &g[i][j], 1);
			if (j < 3)
				write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

int		main()
{
	int i;

	i = 0;
	int** row_view;
	int** col_view;

	row_view = (int**)malloc(sizeof(int*) * 4);
	col_view = (int**)malloc(sizeof(int*) * 4);
	
	while (i < 4)
	{
		row_view[i] = (int*)malloc(sizeof(int) * 2);
		col_view[i] = (int*)malloc(sizeof(int) * 2);
		i++;
	}
	
	i = 0;
	while (i < 4)
	{
		g_grid[i] = (int*)malloc(sizeof(int) * 4);
		i++;
	}

	col_view[0][0] = 2;
	col_view[1][0] = 3;
	col_view[2][0] = 2;
	col_view[3][0] = 1;
	col_view[0][1] = 3;
	col_view[1][1] = 1;
	col_view[2][1] = 2;
	col_view[3][1] = 2;
	row_view[0][0] = 3;
	row_view[1][0] = 1;
	row_view[2][0] = 2;
	row_view[3][0] = 2;
	row_view[0][1] = 1;
	row_view[1][1] = 3;
	row_view[2][1] = 2;
	row_view[3][1] = 2;

	initialize_g_grid();
	process(row_view, col_view);
	print_g_grid();
	return 0;
}
