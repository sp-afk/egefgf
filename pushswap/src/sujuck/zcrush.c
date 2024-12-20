/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zcrush.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 03:19:36 by mdoumane          #+#    #+#             */
/*   Updated: 2024/12/05 02:15:42 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psutiles.h"

int	skillysus(int ftn, int crush, t_dlist *l)
{
	t_dlist	*n;
	int		f;

	n = l;
	f = 1;
	while (n)
	{
		if (n->data > ftn || crush >= n->data)
			f = 1;
		else
			return (0);
		n = n->next;
	}
	return (f);
}

int	find_crush(int pca, t_dlist *list, int smb, int bgb)
{
	t_dlist	*crush;
	int		index;
	int		crush_index;

	crush = list;
	index = 0;
	crush_index = 0;
	if (!list)
		return (-1);
	while (crush)
	{
		if ((pca > crush->data) && (skillysus(pca, crush->data, list) == 1))
		{
			crush_index = index;
			break ;
		}
		crush = crush->next;
		index++;
	}
	if (pca < smb || pca > bgb)
	{
		crush_index = cmpt_big(list);
	}
	return (crush_index);
}

int	evil_skillysus(int ftn, int crush, t_dlist *l)
{
	t_dlist	*n;
	int		f;

	n = l;
	f = 1;
	while (n)
	{
		if (n->data < ftn || crush <= n->data)
			f = 1;
		else
			return (0);
		n = n->next;
	}
	return (f);
}

int	evil_find_crush(int pca, t_dlist *list, int bgb)
{
	t_dlist	*crush;
	int		index;
	int		crush_index;

	crush = list;
	index = 0;
	crush_index = 0;
	if (!list)
		return (-1);
	while (crush)
	{
		if ((pca < crush->data) && (evil_skillysus(pca, crush->data,
					list) == 1))
		{
			crush_index = index;
			break ;
		}
		crush = crush->next;
		index++;
	}
	if (pca > bgb)
	{
		crush_index = cmpt_small(list);
	}
	return (crush_index);
}
