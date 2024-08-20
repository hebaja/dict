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
	s_table	s_tab;

	matrix = create_matrix(fd_matrix, buf_matrix);
	if (argc >= 2)
	{
		table = build_table(argv[1]);
		populate_table(argv[1], table);
		s_tab.table = table;
		s_tab.height = get_table_height(argv[1]);
		write_number(s_tab, matrix);
	}
	i = 0;
	while (i < get_file_lines_qt() - 1)
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	i = 0;
	while (i < (get_table_height(argv[1])))
	{
		free(table[i]);
		table[i] = NULL;
		i++;
	}
	free(table);
	return (0);
}
