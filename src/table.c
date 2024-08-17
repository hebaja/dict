#include "dict.h"
#include <stdlib.h>

int	get_table_height(char *str)
{
	int	len;
	int	height;
	int mod;

	len = ft_strlen(str);
	height = len / 3;
	mod = len % 3;
	if (mod == 1 || mod == 2)
		height += 1;
	return height;
}

void	print_table(int x, char **table)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ft_putstr(table[i]);
		ft_putchar('\n');
		i++;
	}
}

char	**build_table(char *str)
{
	int	x;
	int j;
	int	i;
	char	**table;

	x = get_table_height(str);

	i = 0;
	table = (char **)malloc(sizeof(char *) * x);
	if (table == NULL)
		return NULL;
	while (i < x)
	{
		table[i] = (char *)malloc(sizeof(char) * 4);
		if (table[i] == NULL)
			return NULL;
		i++;
	}
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < 3)
		{
			table[i][j] = '0';
			j++;
		}
		table[i][j] = '\0';
		i++;
	}
	// print_table(x, table);
	return table;
}

void	populate_table(char *str, char **table)
{
	int	x;
	int y;
	int str_len;

	x = get_table_height(str) - 1;
	str_len = ft_strlen(str) - 1;
	while (x >= 0 && str_len >= 0)
	{
		y = 3;
		table[x][y] = '\0';
		y--;
		while (y >= 0 && str_len >= 0)
		{
			table[x][y]	= str[str_len];
			y--;
			str_len--;
		}
		x--;
	}
	ft_putchar(10);
	print_table(get_table_height(str), table);
}

