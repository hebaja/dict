#ifndef CASES_H
# define CASES_H

void	extract_word(char *str);
void	parse_unit(int index, char **matrix);
void	parse_decimal(int index, char **matrix);
void	parse_decimal_teen(int index, char **matrix);
void	write_number(int height, char **table, char **matrix);
void	case_decillion(int x, int y, char **table, char **matrix);
void	case_nonillion(int x, int y, char **table, char **matrix);
void	case_octillion(int x, int y, char **table, char **matrix);
void	case_septillion(int x, int y, char **table, char **matrix);
int	is_end(int x, int y, int height, char **table);

#endif
