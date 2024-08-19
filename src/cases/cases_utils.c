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

int  is_all_zero(int height, char **table)
{
  int  x;
  int  y;

  x = 0;
	while (x < height)
	{
		y = 0;
		while (y < 3)
		{
			if (table[x][y] != '0')
				return (0);
			y++;
		}
		x++;
	}
  return (1);
}

void	write_number(struct s_table s_tab, char **matrix)
{
	int	x;
	int	y;

  if (is_all_zero(s_tab.height, s_tab.table))
    extract_word(matrix[0]);
  else
  {
  	x = 0;
  	while (x < s_tab.height)
  	{
  		y = 0;
  		while (y < 3)
		  {
        if ((s_tab.height - x) == 13)
        {
          case_undecillion(x, y, s_tab, matrix);
          y++;
        } else if ((s_tab.height - x) == 12)
  			{
  				case_decillion(x, y, s_tab, matrix);
  				y++;
  			} else if ((s_tab.height - x) == 11)
  			{
  				case_nonillion(x, y, s_tab, matrix);
  				y++;
  			} else if ((s_tab.height - x) == 10)
  			{
  				case_octillion(x, y, s_tab, matrix);
  				y++;
  			} else if ((s_tab.height - x) == 9)
  			{
  				case_septillion(x, y, s_tab, matrix);
  				y++;
  			} else if ((s_tab.height - x) == 8)
  			{
  				case_sextillion(x, y, s_tab, matrix);
  				y++;
  			} else if ((s_tab.height - x) == 7)
  			{
  				case_quintillion(x, y, s_tab, matrix);
  				y++;
  			} else if ((s_tab.height - x) == 6)
  			{
  				case_quadrillion(x, y, s_tab, matrix);
  				y++;
  			} else if ((s_tab.height - x) == 5)
  			{
  				case_trillion(x, y, s_tab, matrix);
  				y++;
  			} else if ((s_tab.height - x) == 4)
  			{
			  	case_billion(x, y, s_tab, matrix);
		  		y++;
	  		} else if ((s_tab.height - x) == 3)
  			{
			  	case_million(x, y, s_tab, matrix);
		  		y++;
	  		} else if ((s_tab.height - x) == 2)
  			{
  				case_thousand(x, y, s_tab, matrix);
  				y++;
  			} else if ((s_tab.height - x) == 1)
  			{
  				case_hundred(x, y, s_tab, matrix);
  				y++;
  			} else
  				y++;
  		}
  		x++;
  	}
  }
}
