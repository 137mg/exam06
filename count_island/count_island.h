#ifndef COUNT_ISLAND_H
# define COUNT_ISLAND_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		ft_strlen(char *str);
int		ft_find_nl(char *str);
void	ft_bzero(char *str, int len);
char	*ft_calloc(int len);
char	*ft_strjoin(char *str1, char *str2);

char	*read_file(int fd, char *content);
int		check_file(char *content);
int		exit_error(void);

void	count_island(char *str);
char	check_env(char *str, int i, int len);
void	reset_str(char *str);

#endif