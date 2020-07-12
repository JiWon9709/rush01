/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlee <ing5751@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 17:03:21 by jlee              #+#    #+#             */
/*   Updated: 2020/07/12 20:30:54 by jlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid_input(int argc, char *argv[])
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

void	input_to_array(char *argv[], int **row_view, int **col_view)
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
