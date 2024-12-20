#include "psutiles.h"

void	make_tic(int ra, int rb, t_dlist **a, t_dlist **b)
{
	int	rr = 0;

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
	int	rrr = 0;

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

void	make_tic_tac(int sla, int slb, int pca, int pcb, t_dlist **a, t_dlist **b)
{
	int	rb = 0;
	int	ra = 0;
	int	rrb = 0;
	int	rra = 0;

	if (pca <= (sla / 2))
		ra = pca;
	else
		rra = sla - pca;
	if (pcb <= (slb / 2))
		rb = pcb;
	else
		rrb = slb - pcb;
	make_tic(ra, rb, a, b);
	make_tac(rra, rrb, a, b);
}

void treistheloneliestnb(t_dlist **a, t_dlist **b)
{
	int bg = big(*a);
	int sza = lstsize(*a);
	int szb = lstsize(*b);
	int devil = 0;

	if (b)
		algotr(a);
	while (szb != 0)
	{
		devil = evil_find_crush((*b)->data, *a, bg);
		make_tic_tac(sza, szb, devil, 0, a, b);
		pa(b, a);
		bg = big(*a);
		sza++;
		szb--;
	}
}

void end_game(t_dlist **a)
{
	int sza = lstsize(*a);
	int lo = cmpt_small(*a);

	if (lo == 0)
		return;
	else
	{
		if (lo < sza/2)
			rn(a, NULL, lo, 24);
		else
			rn(a, NULL, (sza - lo), 224);
	}
}
