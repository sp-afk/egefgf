/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notaireI.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:37:49 by mdoumane          #+#    #+#             */
/*   Updated: 2024/11/28 01:37:52 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psutiles.h"

void	del_head(t_dlist **list)
{
	t_dlist	*temp;

	if (!list || !(*list))
		return ;
	temp = *list;
	*list = (*list)->next;
	if (*list)
		(*list)->prev = NULL;
	free(temp);
}

void	lst_clear(t_dlist **list)
{
	while (*list)
		del_head(list);
}

t_dlist	*dlist_new(int data)
{
	t_dlist	*node;

	node = malloc(sizeof(t_dlist));
	if (!node)
		return (NULL);
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	put_tail(t_dlist **list, int data)
{
	t_dlist	*new_node;
	t_dlist	*tail;

	new_node = dlist_new(data);
	if (!new_node)
		return ;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	tail = *list;
	while (tail->next)
		tail = tail->next;
	tail->next = new_node;
	new_node->prev = tail;
}

void	put_head(t_dlist **list, int data)
{
	t_dlist	*new_node;

	new_node = dlist_new(data);
	if (!new_node)
		return ;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	new_node->next = *list;
	(*list)->prev = new_node;
	*list = new_node;
}
