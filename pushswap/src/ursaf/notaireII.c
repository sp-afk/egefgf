/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notaireII.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:35:01 by mdoumane          #+#    #+#             */
/*   Updated: 2024/12/05 02:15:42 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psutiles.h"

t_dlist	*get_head(t_dlist *list)
{
	if (!list)
		return (NULL);
	while (list->prev)
		list = list->prev;
	return (list);
}

void	printlist(t_dlist *list)
{
	t_dlist	*node;

	node = list;
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

int	lstsize(t_dlist *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	make_circular(t_dlist **list)
{
	t_dlist	*last;

	if (!list || !*list)
		return ;
	last = *list;
	while (last->next)
		last = last->next;
	last->next = *list;
	(*list)->prev = last;
}

void	dead_circular(t_dlist **list)
{
	t_dlist	*tail;

	if (!list || !*list)
		return ;
	tail = *list;
	while (tail->next && tail->next != *list)
		tail = tail->next;
	if (tail->next == *list)
	{
		tail->next = NULL;
		(*list)->prev = NULL;
	}
}
