/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notaireIII.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:30:27 by mdoumane          #+#    #+#             */
/*   Updated: 2024/12/05 02:15:42 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psutiles.h"

int	cmpt_small(t_dlist *list)
{
	int		min;
	int		index;
	int		min_index;
	t_dlist	*current;

	min = list->data;
	index = 0;
	min_index = 0;
	current = list;
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

int	cmpt_big(t_dlist *list)
{
	int		max;
	int		index;
	int		max_index;
	t_dlist	*current;

	max = list->data;
	index = 0;
	max_index = 0;
	current = list;
	while (current)
	{
		if (current->data > max)
		{
			max = current->data;
			max_index = index;
		}
		current = current->next;
		index++;
	}
	return (max_index);
}

int	small(t_dlist *list)
{
	int		min;
	int		index;
	t_dlist	*current;

	min = list->data;
	index = 0;
	current = list;
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
		}
		current = current->next;
		index++;
	}
	return (min);
}

int	big(t_dlist *list)
{
	int		max;
	int		index;
	t_dlist	*current;

	max = list->data;
	index = 0;
	current = list;
	while (current)
	{
		if (current->data > max)
		{
			max = current->data;
		}
		current = current->next;
		index++;
	}
	return (max);
}
