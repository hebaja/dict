#include <stdio.h>

void	debug_is_end(int x, int y, int height, char **table)
{

	printf("\nx - > %d | heigh -> %d | ---> %s", x, height, table[x]);

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
	printf("\nx - > %d ---> %s ---> valid %d\n", x, table[x], valid);
	while (x < height)
	{
		y = 0;
		printf("\n\n**************");
		while (y < 3)
		{
			printf("%c", table[x][y]);

			if (table[x][y] != '0')
			{
				printf("entering not valid -> %d\n", table[x][y]);
				valid = 0;
			}
			y++;
		}
		printf("\n\n**************");
		x++;
	}
	printf("valid -> %d\n", valid);
}
