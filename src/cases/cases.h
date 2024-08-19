#ifndef CASES_H
# define CASES_H

struct s_table
{
	char	**table;
	int	height;
};
typedef struct s_table s_table;

void	extract_word(char *str);
void	parse_unit(int index, char **matrix);
void	parse_decimal(int index, char **matrix);
void	parse_decimal_teen(int index, char **matrix);
void	write_number(struct s_table, char **matrix);
void	case_decillion(int x, int y, char **table, char **matrix);
void	case_nonillion(int x, int y, char **table, char **matrix);
void	case_octillion(int x, int y, char **table, char **matrix);
void	case_septillion(int x, int y, char **table, char **matrix);
void	case_sextillion(int x, int y, char **table, char **matrix);
void	case_quintillion(int x, int y, char **table, char **matrix);
void	case_quadrillion(int x, int y, char **table, char **matrix);
int	is_end(int x, int y, int height, char **table);
void	debug_is_end(int x, int y, int height, char **table);

#endif
