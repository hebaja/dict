#include "../dict.h"
#include "cases.h"
#include "../utils/ft.h"

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

void	parse_unit(int index, char **matrix)
{
	extract_word(matrix[index - 48]);
}

void	parse_decimal(int index, char **matrix)
{
	extract_word(matrix[index - 30]);
}

void	parse_decimal_teen(int index, char **matrix)
{
	extract_word(matrix[index - 38]);
}

int	is_end(int x, int y, int height, char **table)
{
	int valid;

	y++;
	valid = 1;
	while (y < 3)
	{
		if (table[x][y] != '0')
			valid = 0;
		y++;
	}
	x++;
	while (x < height)
	{
		y = 0;
		while (y < 3)
		{
			if (table[x][y] != '0')
				valid = 0;
			y++;
		}
		x++;
	}
	return (valid);
}

void	write_number(struct s_table s_tab, char **matrix)
{
	int	x;
	int	y;

	x = 0;
	while (x < s_tab.height)
	{
		y = 0;
		while (y < 3)
		{
			if ((y == 0 && x == 0 && s_tab.table[x][y] == '0') || \
			(y == 1 && x == 0 && s_tab.table[x][y] == '0' && \
			s_tab.table[x][y - 1] == '0')) // It makes index iterate case first names are zeroes
				y++;
			else if ((s_tab.height - x) == 13 && y == 2 && s_tab.table[x][y] != '0')
			{
				parse_unit(s_tab.table[x][y], matrix);
				ft_putchar(' ');
				extract_word(matrix[40]);
				if (!is_end(x, y, s_tab.height, s_tab.table))
					ft_putchar(' ');
				y++;
			}
			else if ((s_tab.height - x) == 12)
			{
				case_decillion(x, y, s_tab.table, matrix);
				y++;
			}
			else if ((s_tab.height - x) == 11)
			{
				case_nonillion(x, y, s_tab.table, matrix);
				y++;
			}
			else if ((s_tab.height - x) == 10)
			{
				case_octillion(x, y, s_tab.table, matrix);
				y++;
			}
			else if ((s_tab.height - x) == 9)
			{
				case_septillion(x, y, s_tab.table, matrix);
				y++;
			}
			else if ((s_tab.height - x) == 8)
			{
				case_sextillion(x, y, s_tab.table, matrix);
				y++;
			}
			else if ((s_tab.height - x) == 7)
			{
				case_quintillion(x, y, s_tab.table, matrix);
				y++;
			}
			else if ((s_tab.height - x) == 6)
			{
				case_quadrillion(x, y, s_tab.table, matrix);
				y++;
			}
			else
				y++;
		}
		x++;
	}
}
