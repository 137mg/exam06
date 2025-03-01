#ifndef ISLAND_H
# define ISLAND_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define LINE_LEN 1024


int		ft_strlen(char *str);
int		ft_find_nl(char *str);
void	ft_bzero(char *str, int len);
char	*ft_calloc(int len);
char	*ft_strjoin(char *str1, char *str2);

char	*read_file(int fd);
int		check_file(char *content);
int		exit_error(void);

void	island(char *str);

#endif