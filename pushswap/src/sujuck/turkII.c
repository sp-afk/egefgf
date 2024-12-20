/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkII.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 03:19:55 by mdoumane          #+#    #+#             */
/*   Updated: 2024/12/05 02:15:42 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psutiles.h"

void	make_tic(int ra, int rb, t_dlist **a, t_dlist **b)
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
	rn(a, b, ra, 24);
	rn(a, b, rb, 26);
	rn(a, b, rr, 22);
}

void	make_tac(int rra, int rrb, t_dlist **a, t_dlist **b)
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
	rn(a, b, rra, 224);
	rn(a, b, rrb, 226);
	rn(a, b, rrr, 222);
}

void	make_tic_tac(int pca, int pcb, t_dlist **a, t_dlist **b)
{
	int	rb;
	int	ra;
	int	rrb;
	int	rra;

	rb = 0;
	ra = 0;
	rrb = 0;
	rra = 0;
	if (pca <= (lstsize(*a) / 2))
		ra = pca;
	else
		rra = lstsize(*a) - pca;
	if (pcb <= (lstsize(*b) / 2))
		rb = pcb;
	else
		rrb = lstsize(*b) - pcb;
	make_tic(ra, rb, a, b);
	make_tac(rra, rrb, a, b);
}

void	treistheloneliestnb(t_dlist **a, t_dlist **b)
{
	int	bg;
	int	sza;
	int	szb;
	int	devil;

	bg = big(*a);
	sza = lstsize(*a);
	szb = lstsize(*b);
	devil = 0;
	if (b)
		algotr(a);
	while (szb != 0)
	{
		devil = evil_find_crush((*b)->data, *a, bg);
		make_tic_tac(devil, 0, a, b);
		pa(b, a, 1);
		bg = big(*a);
		sza++;
		szb--;
	}
}

void	end_game(t_dlist **a)
{
	int	sza;
	int	lo;

	sza = lstsize(*a);
	lo = cmpt_small(*a);
	if (lo == 0)
		return ;
	else
	{
		if (lo < sza / 2)
			rn(a, NULL, lo, 24);
		else
			rn(a, NULL, (sza - lo), 224);
	}
}
