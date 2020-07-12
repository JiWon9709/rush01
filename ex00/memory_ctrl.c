/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_ctrl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlee <ing5751@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 17:06:48 by jlee              #+#    #+#             */
/*   Updated: 2020/07/12 17:30:43 by jlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	assign_memory(int **grid, int **row_view, int **col_view)
{
	int i;

	i = 0;
	while (i < 4)
	{
		grid[i] = (int*)malloc(sizeof(int) * 4);
		row_view[i] = (int*)malloc(sizeof(int) * 2);
		col_view[i] = (int*)malloc(sizeof(int) * 2);
		i++;
	}
}

void	free_variables(int **grid, int **row_view, int **col_view)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(grid[i]);
		free(row_view[i]);
		free(col_view[i]);
		i++;
	}
	free(grid);
	free(row_view);
	free(col_view);
}
