#include "psutiles.h"

int	count_tic(int ra, int rb)
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
	return (ra + rb + rr);
}

int	count_tac(int rra, int rrb)
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

	return (rra + rrb + rrr);
}

int	count_tic_tac(int sla, int slb, int pca, int pcb)
{
	int	rb = 0;
	int	ra = 0;
	int	rrb = 0;
	int	rra = 0;
	int	all = 0;

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

int	compar_clock(int *crush, int sza, int szb, int bga, int sma, t_dlist *a, t_dlist *b, int love)
{
	int index = 0;
	int chp_index = 0;
	int current = 0;
	int chp = INT_MAX;
	int smda;

	while (a)
	{
		smda = a->data;
		*crush = find_crush(smda, b, sma, bga);
		current = count_tic_tac(sza, szb, index, *crush);

		if (current < chp)
		{
			chp = current;
			chp_index = index;
			love = *crush;
		}
		a = a->next;
		index++;
		if (index >= sza)
			break;
	}
	*crush = love;

	return chp_index;
}


void	perfect_clock(t_dlist **a, t_dlist **b, int chp, int lv)
{
	int sza = lstsize(*a);
	int szb = lstsize(*b);
	int bda = big(*b);
	int sma = small(*b);
	int crush = 0;

	while (sza > 3)
	{
		chp = compar_clock(&crush, sza, szb, bda, sma, *a, *b, lv);
		printf("%d", chp);
		make_tic_tac(sza, szb, chp, crush, a, b);
		pb(a, b);
		bda = big(*b);
		sma = small(*b);
		sza--;
		szb++;
	}
}
