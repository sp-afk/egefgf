/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dilemmeIII.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:05:06 by mdoumane          #+#    #+#             */
/*   Updated: 2024/11/27 19:05:06 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psutiles.h"

void	ra(t_dlist **stacka, int z)
{
	if (!stacka || !*stacka || !(*stacka)->next)
		return ;
	make_circular(stacka);
	*stacka = (*stacka)->next;
	dead_circular(stacka);
	if (z == 1)
		printf("ra\n");
}

void	rb(t_dlist **stackb, int z)
{
	if (!stackb || !*stackb || !(*stackb)->next)
		return ;
	make_circular(stackb);
	*stackb = (*stackb)->next;
	dead_circular(stackb);
	if (z == 1)
		printf("rb\n");
}

void	rra(t_dlist **stacka, int z)
{
	if (!stacka || !*stacka || !(*stacka)->next)
		return ;
	make_circular(stacka);
	*stacka = (*stacka)->prev;
	dead_circular(stacka);
	if (z == 1)
		printf("rra\n");
}

void	rrb(t_dlist **stackb, int z)
{
	if (!stackb || !*stackb || !(*stackb)->next)
		return ;
	make_circular(stackb);
	*stackb = (*stackb)->prev;
	dead_circular(stackb);
	if (z == 1)
		printf("rrb\n");
}
