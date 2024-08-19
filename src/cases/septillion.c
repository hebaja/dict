#include "cases.h"
#include "../utils/ft.h"

void	case_septillion(int x, int y, s_table s_tab, char **matrix)
{
	if (y == 0 && s_tab.table[x][y] != '0')
	{
		parse_unit(s_tab.table[x][y], matrix);
		ft_putchar(' ');
		extract_word(matrix[28]);
		ft_putchar(' ');
	}
	if (y == 1 && s_tab.table[x][y] != '0')
	{
		if (s_tab.table[x][y] == '1')
		{
			parse_decimal_teen(s_tab.table[x][y + 1], matrix);
			ft_putchar(' ');
		}
		else
		{
			parse_decimal(s_tab.table[x][y], matrix);
			if (!is_end(x, y, s_tab.height, s_tab.table) && s_tab.table[x][y + 1] != '0')
				ft_putchar('-');
			else
				ft_putchar(' ');
		}
	}
	if (y == 2 && s_tab.table[x][y] != '0')
	{
		if (s_tab.table[x][y - 1] != '1')
		{
			parse_unit(s_tab.table[x][y], matrix);
			ft_putchar(' ');
		}
	}
	if (y == 2 && (s_tab.table[x][y] != '0' || s_tab.table[x][y - 1] != '0' || s_tab.table[x][y - 2] != '0'))
	{
		extract_word(matrix[36]);
		if (!is_end(x, y, s_tab.height, s_tab.table))
			ft_putchar(' ');
	}
}

