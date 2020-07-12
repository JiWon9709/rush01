/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlee <ing5751@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 17:08:17 by jlee              #+#    #+#             */
/*   Updated: 2020/07/12 20:30:26 by jlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	assign_memory(int **grid, int **row_view, int **col_view);
int		is_valid_input(int argc, char *argv[]);
void	input_to_array(char *argv[], int **row_view, int **col_view);
void	initialize_grid(int **grid);
int		solve(int **grid, int **row_view, int **col_view);
void	print_grid(int **grid);
void	free_variables(int **grid, int **row_view, int **col_view);

int		main(int argc, char *argv[])
{
	int	**grid;
	int	**row_view;
	int	**col_view;

	grid = (int**)malloc(sizeof(int*) * 4);
	row_view = (int**)malloc(sizeof(int*) * 4);
	col_view = (int**)malloc(sizeof(int*) * 4);
	assign_memory(grid, row_view, col_view);
	if (!is_valid_input(argc, argv))
	{
		write(1, "Error\n", 6);
		free_variables(grid, row_view, col_view);
		return (1);
	}
	input_to_array(argv, row_view, col_view);
	initialize_grid(grid);
	if (solve(grid, row_view, col_view))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	free_variables(grid, row_view, col_view);
	return (0);
}
