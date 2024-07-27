#include "g_diam.h"

t_lst	**parse_arg(char *arg)
{
	t_lst	**lst;
	t_lst	*node;
	int		n1;
	int		n2;
	int		i;

	lst = malloc(sizeof(t_lst *));
	if (!lst)
		return (NULL);
	*lst = NULL;
	i = 0;
	while (i != -1)
	{
		n1 = ft_atoi(&arg[i]);
		i = ft_skip(arg, i, '-');
		n2 = ft_atoi(&arg[i]);
		i = ft_skip(arg, i, ' ');
		node = lstnew(n1, n2);
		if (!node)
		{
			lstfree(lst);
			return (NULL);
		}
		lstadd(lst, node);
	}
	return (lst);
}

int	isdup(t_lst **lst, t_lst *node)
{
	t_lst	*tmp;

	tmp = *lst;
	while (tmp != node)
	{
		if (tmp->n1 == node->n1 || tmp->n1 == node->n2)
		{
			if (tmp->n2 == node->n1 || tmp->n2 == node->n2)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	remove_dups(t_lst **lst)
{
	t_lst	*tmp;
	t_lst	*node;

	tmp = *lst;
	while (tmp)
	{
		node = tmp->next;
		if (node && isdup(lst, node) == 1)
		{
			tmp->next = node->next;
			free(node);
		}
		else
			tmp = tmp->next;
	}
}

int	find_max(t_lst **lst, int n, int oldmax)
{
	t_lst	*tmp;
	int		tmpmax;
	int		max;

	max = oldmax;
	tmpmax = 0;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->used == 0)
		{
			tmp->used = 1;
			if (tmp->n1 == n)
				tmpmax = find_max(lst, tmp->n2, oldmax + 1);
			if (tmp->n2 == n)
				tmpmax = find_max(lst, tmp->n1, oldmax + 1);
			if (tmpmax > max)
				max = tmpmax;
			tmp->used = 0;
		}
		tmp = tmp->next;
	}
	return (max);
}

int	main(int argc, char **argv)
{
	t_lst	**lst;
	t_lst	*tmp;
	int		max;
	int		tmpmax;

	if (argc == 2)
	{
		lst = parse_arg(argv[1]);
		if (!lst)
			return (1);
		remove_dups(lst);
		max = 0;
		tmp = *lst;
		while (tmp)
		{
			tmpmax = find_max(lst, tmp->n1, 0);
			if (tmpmax > max)
				max = tmpmax;
			tmpmax = find_max(lst, tmp->n2, 0);
			if (tmpmax > max)
				max = tmpmax;
			tmp = tmp->next;
		}
		lstfree(lst);
		ft_putnbr(max);
	}
	write(1, "\n", 1);
	return (0);
}
