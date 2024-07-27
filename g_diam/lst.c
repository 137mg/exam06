#include "g_diam.h"

t_lst	*lstnew(int n1, int n2)
{
	t_lst	*node;

	node = malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->n1 = n1;
	node->n2 = n2;
	node->next = NULL;
	return (node);
}

void	lstadd(t_lst **lst, t_lst *node)
{
	t_lst	*tmp;

	if (!*lst)
	{
		*lst = node;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	lstfree(t_lst **lst)
{
	t_lst	*tmp1;
	t_lst	*tmp2;

	tmp1 = *lst;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	free(lst);
}
