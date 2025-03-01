#include "g_diam.h"

int	is_link(int *links, int n1, int n2)
{
	int	i;

	i = 0;
	while (links[i] != -1)
	{
		if (n1 == links[i] || n2 == links[i])
		{
			if (n1 == links[i + 1] || n2 == links[i + 1])
				return (1);
		}
		i += 2;
	}
	return (0);
}

int	find_max(t_node **nodelist, int *links, int n, int oldmax)
{
	t_node	*tmp;
	int		max;
	int		newmax;

	max = oldmax;
	tmp = *nodelist;
	while (tmp)
	{
		if (tmp->used == 0 && is_link(links, n, tmp->n) == 1)
		{
			tmp->used = 1;
			newmax = find_max(nodelist, links, tmp->n, oldmax + 1);
			tmp->used = 0;
			if (newmax > max)
				max = newmax;
		}
		tmp = tmp->next;
	}
	return (max);
}

int	g_diam(t_node **nodelist, int *links)
{
	t_node	*tmp;
	int		max;
	int		newmax;

	max = 1;
	tmp = *nodelist;
	while (tmp)
	{
		tmp->used = 1;
		newmax = find_max(nodelist, links, tmp->n, 1);
		tmp->used = 0;
		if (newmax > max)
			max = newmax;
		tmp = tmp->next;
	}
	return (max);
}

int	main(int argc, char **argv)
{
	t_node	**nodelist;
	int		*links;
	int		max;

	if (argc == 2)
	{
		links = parse_links(argv[1]);
		if (!links)
			return (1);
		nodelist = parse_nodes(links);
		if (!nodelist)
		{
			free(links);
			return (1);
		}
		max = g_diam(nodelist, links);
		free(links);
		nodefree(nodelist);
		ft_putnbr(max);
	}
	write(1, "\n", 1);
	return (0);
}
