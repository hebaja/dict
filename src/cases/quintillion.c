#include "cases.h"
#include "../dict.h"
#include "../utils/ft.h"

void	case_quintillion(int x, int y, s_table tab, char **matrix)
{
	if (y == 0 && tab.table[x][y] != '0')
	{
		parse_unit(tab.table[x][y], matrix);
		ft_putchar(' ');
		extract_word(matrix[28]);
		ft_putchar(' ');
	}
	if (y == 1 && tab.table[x][y] != '0')
	{
		if (tab.table[x][y] == '1')
		{
			parse_decimal_teen(tab.table[x][y + 1], matrix);
			ft_putchar(' ');
		}
		else
		{
			parse_decimal(tab.table[x][y], matrix);
			if (!is_end(x, y, tab.height, tab.table) && tab.table[x][y + 1] != '0')
				ft_putchar('-');
			else
				ft_putchar(' ');
		}
	}
	if (y == 2 && tab.table[x][y] != '0')
	{
		if (tab.table[x][y - 1] != '1')
		{
			parse_unit(tab.table[x][y], matrix);
			ft_putchar(' ');
		}
	}
	if (y == 2 && (tab.table[x][y] != '0' || tab.table[x][y - 1] != '0' || tab.table[x][y - 2] != '0'))
	{
		extract_word(matrix[34]);
		// debug_is_end(x, y, tab.height, tab.table);

		if (!is_end(x, y, tab.height, tab.table))
			ft_putchar(' ');
	}
}
