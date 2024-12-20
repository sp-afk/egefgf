/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkI.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 03:19:58 by mdoumane          #+#    #+#             */
/*   Updated: 2024/12/06 21:38:50 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psutiles.h"

int	count_tic(int ra, int rb)
{
	int	rr;

	rr = 0;
	if ((ra != 0 && rb != 0))
	{
		if (ra >= rb)
		{
			rr = rb;
			ra = (ra - rb);
			rb = 0;
		}
		else
		{
			rr = ra;
			rb = rb - ra;
			ra = 0;
		}
	}
	return (ra + rb + rr);
}

int	count_tac(int rra, int rrb)
{
	int	rrr;

	rrr = 0;
	if ((rra != 0 && rrb != 0))
	{
		if (rra >= rrb)
		{
			rrr = rrb;
			rra = rra - rrb;
			rrb = 0;
		}
		else
		{
			rrr = rra;
			rrb = rrb - rra;
			rra = 0;
		}
	}
	return (rra + rrb + rrr);
}

int	count_tic_tac(int sla, int slb, int pca, int pcb)
{
	int	rb;
	int	ra;
	int	rrb;
	int	rra;
	int	all;

	rb = 0;
	ra = 0;
	rrb = 0;
	rra = 0;
	all = 0;
	if (pca <= (sla / 2))
		ra = pca;
	else
		rra = sla - pca;
	if (pcb <= (slb / 2))
		rb = pcb;
	else
		rrb = slb - pcb;
	all += count_tic(ra, rb);
	all += count_tac(rra, rrb);
	return (all);
}

int	compar_clock(int *crush, t_dlist *a, t_dlist *b, int love)
{
	int	index;
	int	chp_index;
	int	current;
	int	chp;

	index = 0;
	chp = INT_MAX;
	while (a)
	{
		*crush = find_crush(a->data, b, small(b), big(b));
		current = count_tic_tac(lstsize(a), lstsize(b), index, *crush);
		if (current < chp)
		{
			chp = current;
			chp_index = index;
			love = *crush;
		}
		a = a->next;
		index++;
		if (index >= lstsize(a))
			break ;
	}
	*crush = love;
	return (chp_index);
}

void	perfect_clock(t_dlist **a, t_dlist **b, int chp, int lv)
{
	int	sza;
	int	crush;

	sza = lstsize(*a);
	crush = 0;
	while (sza > 3)
	{
		chp = compar_clock(&crush, *a, *b, lv);
		printf("%d", chp);
		make_tic_tac(chp, crush, a, b);
		pb(a, b, 1);
		sza--;
	}
}
