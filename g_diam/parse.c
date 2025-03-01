#include "g_diam.h"

int	*parse_links(char *str)
{
	int		*links;
	int		n;
	int		i;
	int		j;

	n = ft_count_dash(str);
	links = malloc(sizeof(int) * (n * 2 + 1));
	if (!links)
		return (NULL);
	i = 0;
	j = 0;
	while (i != -1)
	{
		links[j] = ft_atoi(&str[i]);
		i = ft_skip(str, i, '-');
		j++;
		links[j] = ft_atoi(&str[i]);
		i = ft_skip(str, i, ' ');
		j++;
	}
	links[j] = -1;
	return (links);
}

t_node	**parse_nodes(int *links)
{
	t_node	**nodelist;
	t_node	*node;
	int		i;

	nodelist = malloc(sizeof(t_node *));
	if (!nodelist)
		return (NULL);
	*nodelist = NULL;
	i = 0;
	while (links[i] != -1)
	{
		if (is_new_number(nodelist, links[i]) == 1)
		{
			node = nodenew(links[i]);
			if (!node)
			{
				nodefree(nodelist);
				return (NULL);
			}
			nodeadd(nodelist, node);
		}
		i++;
	}
	return (nodelist);
}

int	is_new_number(t_node **nodelist, int n)
{
	t_node	*tmp;

	tmp = *nodelist;
	while (tmp)
	{
		if (tmp->n == n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
