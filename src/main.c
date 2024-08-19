#include <stdio.h>
#include <stdlib.h>
#include "dict.h"
#include "cases/cases.h"
#include "utils/ft.h"

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
