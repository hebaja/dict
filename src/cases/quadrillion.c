#include "cases.h"
#include "../utils/ft.h"

void	case_quadrillion(int x, int y, char **table, char **matrix)
{
	if (y == 0 && table[x][y] != '0')
	{
		parse_unit(table[x][y], matrix);
		ft_putchar(' ');
		extract_word(matrix[28]);
		ft_putchar(' ');
	}
	if (y == 1 && table[x][y] != '0')
	{
		if (table[x][y] == '1')
		{
			parse_decimal_teen(table[x][y + 1], matrix);
			ft_putchar(' ');
		}
		else
		{
			parse_decimal(table[x][y], matrix);
			if (!is_end(x, y, 6, table) && table[x][y + 1] != '0')
				ft_putchar('-');
			else
				ft_putchar(' ');
		}
	}
	if (y == 2 && table[x][y] != '0')
	{
		if (table[x][y - 1] != '1')
		{
			parse_unit(table[x][y], matrix);
			ft_putchar(' ');
		}
	}
	if (y == 2 && (table[x][y] != '0' || table[x][y - 1] != '0' || table[x][y - 2] != '0'))
	{
		extract_word(matrix[33]);
		if (!is_end(x, y, 6, table))
			ft_putchar(' ');
	}
}

