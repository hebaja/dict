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

void	write_number(int height, char **table, char **matrix)
{
	int	x;
	int	y;

	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < 3)
		{
			if ((y == 0 && x == 0 && table[x][y] == '0') || \
			(y == 1 && x == 0 && table[x][y] == '0' && \
			table[x][y - 1] == '0')) // It makes index iterate case first names are zeroes
				y++;
			else if ((height - x) == 13 && y == 2 && table[x][y] != '0')
			{
				parse_unit(table[x][y], matrix);
				ft_putchar(' ');
				extract_word(matrix[40]);
				if (!is_end(x, y, height, table))
					ft_putchar(' ');
				y++;
			}
			else if ((height - x) == 12)
			{
				case_decillion(x, y, table, matrix);
				y++;
			}
			else if ((height - x) == 11)
			{
				case_nonillion(x, y, table, matrix);
				y++;
			}
			else if ((height - x) == 10)
			{
				case_octillion(x, y, table, matrix);
				y++;
			}
			else if ((height - x) == 9)
			{
				case_septillion(x, y, table, matrix);
				y++;
			}
			else
				y++;
		}
		x++;
	}
}
