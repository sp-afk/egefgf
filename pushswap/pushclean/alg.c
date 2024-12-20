/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:01:47 by mdoumane          #+#    #+#             */
/*   Updated: 2024/11/28 01:01:47 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psutiles.h"

void	algoturk(t_dlist **a, t_dlist **b)
{
	int	chp;
	int	love;

	chp = 0;
	love = 0;
	pb(a, b);
	pb(a, b);
	perfect_clock(a, b, chp, love);
	treistheloneliestnb(a, b);
	end_game(a);
}

void	algotr(t_dlist **a)
{
	int	sm;
	int	bg;

	sm = cmpt_small(*a);
	bg = cmpt_big(*a);
	if (sm == 0 && bg == 1)
	{
		sa(a, 1);
		ra(a, 1);
	}
	if (sm == 1 && bg == 2)
		sa(a, 1);
	if (bg == 0 && sm == 1)
		ra(a, 1);
	if (bg == 1 && sm == 2)
		rra(a, 1);
	if (bg == 0 && sm == 2)
	{
		ra(a, 1);
		sa(a, 1);
	}
}

void	algo(t_dlist **list1, t_dlist **list2)
{
	int	b;

	b = 0;
	while (*list1)
	{
		b = cmpt_small(*list1);
		rn(list1, list2, b, 24);
		pb(list1, list2);
	}
	while (*list2)
	{
		pa(list2, list1);
	}
}

void	altugo(t_dlist **list)
{
	sa(list, 1);
}
