/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dilemmeIV.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:05:00 by mdoumane          #+#    #+#             */
/*   Updated: 2024/11/27 19:05:00 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psutiles.h"

void	rr(t_dlist **stacka, t_dlist **stackb, int z)
{
	if (z == 1)
		printf("rr\n");
	ra(stacka, 0);
	rb(stackb, 0);
}

void	rrr(t_dlist **stacka, t_dlist **stackb, int z)
{
	if (z == 1)
		printf("rrr\n");
	rra(stacka, 0);
	rrb(stackb, 0);
}

void	rn(t_dlist **lista, t_dlist **listb, int n, int nuy)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (nuy == 24)
			ra(lista, 1);
		if (nuy == 26)
			rb(listb, 1);
		if (nuy == 22)
			rr(lista, listb, 1);
		if (nuy == 224)
			rra(lista, 1);
		if (nuy == 226)
			rrb(listb, 1);
		if (nuy == 222)
			rrr(lista, listb, 1);
		i++;
	}
}
