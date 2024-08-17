#ifndef DICT_H
# define DICT_H

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int	ft_strlen(char *str);
void	ft_putstr(char *str);
void	read_file(int fd, char *buf, int file_size);
void    print_matrix(char **matrix);
char 	**create_matrix(int fd, char *buf);
int		get_file_size();
int		get_file_lines_qt();
int	get_table_height(char *str);
void	print_table(int x, char **table);
char	**build_table(char *str);
void	populate_table(char *str, char **table);
int		get_line_width();

#endif
