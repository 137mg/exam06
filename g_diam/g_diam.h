#ifndef G_DIAM_H
# define G_DIAM_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_lst
{
	int				n1;
	int				n2;
	int				used;
	struct s_lst	*next;
}	t_lst;

t_lst	*lstnew(int n1, int n2);
void	lstadd(t_lst **lst, t_lst *node);
void	lstfree(t_lst **lst);

int		ft_skip(char *str, int i, char c);
int		ft_atoi(char *str);
void	ft_putnbr(int n);

t_lst	**parse_arg(char *arg);
int		isdup(t_lst **lst, t_lst *node);
void	remove_dups(t_lst **lst);
int		find_max(t_lst **lst, int n, int oldmax);

#endif