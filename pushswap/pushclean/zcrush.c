#include "psutiles.h"

int skillysus(int ftn, int crush, t_dlist *l)
{
	t_dlist *n = l;
	int f = 1;

	while (n)
	{
		if(n->data > ftn || crush >= n->data)
			f = 1;
		else
			return 0;
		n = n->next;
	}
	return f;
}

int	find_crush(int pca, t_dlist *list, int smb, int bgb)
{


	t_dlist *crush = list;
	int index = 0;
	int crush_index = 0;

	if (!list)
		return -1;

	while (crush)
	{
		if ((pca > crush->data) && (skillysus(pca, crush->data, list) == 1))
		{
			crush_index = index;
			break;
		}
		crush = crush->next;
		index++;
	}

	if(pca < smb || pca > bgb)
	{
		crush_index = cmpt_big(list);
	}
	return crush_index;
}

int evil_skillysus(int ftn, int crush, t_dlist *l)
{
	t_dlist *n = l;
	int f = 1;

	while (n)
	{
		if(n->data < ftn || crush <= n->data)
			f = 1;
		else
			return 0;
		n = n->next;
	}
	return f;
}

int	evil_find_crush(int pca, t_dlist *list, int bgb)
{


	t_dlist *crush = list;
	int index = 0;
	int crush_index = 0;

	if (!list)
		return -1;

	while (crush)
	{
		if ((pca < crush->data) && (evil_skillysus(pca, crush->data, list) == 1))
		{
			crush_index = index;
			break;
		}
		crush = crush->next;
		index++;
	}

	if(pca > bgb)
	{
		crush_index = cmpt_small(list);
	}
	return crush_index;
}
