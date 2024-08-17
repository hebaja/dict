#include <stdio.h>
#include <stdlib.h>
#include "dict.h"

void	extract_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9') && (str[i] != ' ') && (str[i] != ':'))
			ft_putchar(str[i]);
		i++;
	}
}

void	parse(int index, char **matrix)
{
	extract_word(matrix[index]);
}

int	is_end(int x, int y, int height, char **table)
{
	y++;
	while (y < 3)
	{
		if (table[x][y] != '0')
			return (0);
		y++;
	}
	x++;
	while (x < height)
	{
		y = 0;
		if (table[x][y] != '0')
			return (0);
		x++;
	}
	return (1);
}

void	write_number(int height, char **table, char **matrix)
{
	int	x;
	int	y;

	/*
	if (height == 1 && table[0][0] == '0')
	{
		ft_putchar('s');
		ft_putchar(10);
	}
	*/

	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < 3)
		{
			if ((y == 0 && x == 0 && table[x][y] == '0') || \
			(y == 1 && x == 0 && table[x][y] == '0' && table[x][y - 1] == '0'))
				y++;
			if ((height - x) == 13 && y == 2 && table[x][y] != '0')
			{
				parse(table[x][y] - 48, matrix);
				ft_putchar(' ');
				extract_word(matrix[40]);
				if (!is_end(x, y, height, table))
					ft_putchar(' ');
				y++;
			}
			else
				y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	int	fd_matrix;
	int	file_size;
	char	*buf_matrix;
	char	**matrix;
	char	**table;
	int	i;

	//read_file(fd_read, buf_read, file_size);
	matrix = create_matrix(fd_matrix, buf_matrix);
	//print_matrix(matrix);
	if (argc >= 2)
	{
		table = build_table(argv[1]);
		populate_table(argv[1], table);
		write_number(get_table_height(argv[1]), table, matrix);
	}
	i = 0;
	free(matrix);
	while (i < get_file_lines_qt() - 1)
	{
		free(matrix[i]);
		i++;
	}
	// i = 0;
	free(table);
	// printf("%d\n", get_table_height(argv[1]));
	// while (i < (get_table_height(argv[1])))
	// {
		// free(table[0]);
		// free(table[1]);
		// i++;
	// }
	return (0);
}
