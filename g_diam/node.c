#include "g_diam.h"

t_node	*nodenew(int n)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->n = n;
	node->used = 0;
	node->next = NULL;
	return (node);
}

void	nodeadd(t_node **nodelist, t_node *node)
{
	t_node	*tmp;

	if (!*nodelist)
	{
		*nodelist = node;
		return;
	}
	tmp = *nodelist;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	nodefree(t_node **nodelist)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = *nodelist;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	free(nodelist);
}
