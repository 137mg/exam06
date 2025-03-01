#ifndef G_DIAM_H
# define G_DIAM_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				n;
	int				used;
	struct s_node	*next;
}	t_node;

t_node	*nodenew(int n);
void	nodeadd(t_node **nodelist, t_node *node);
void	nodefree(t_node **nodelist);

int		ft_count_dash(char *str);
int		ft_skip(char *str, int i, char c);
int		ft_atoi(char *str);
void	ft_putnbr(int n);

int		*parse_links(char *str);
t_node	**parse_nodes(int *links);
int		is_new_number(t_node **nodelist, int n);

int		is_link(int *links, int n1, int n2);
int		find_max(t_node **nodelist, int *links, int n, int oldmax);
int		g_diam(t_node **nodelist, int *links);

#endif