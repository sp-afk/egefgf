/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dilemmeI.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:05:14 by mdoumane          #+#    #+#             */
/*   Updated: 2024/11/27 19:05:14 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psutiles.h"

void	sa(t_dlist **stacka, int z)
{
	if (!(*stacka) || lstsize(*stacka) < 2)
		return ;
	ft_swap(&((*stacka)->data), &((*stacka)->next->data));
	if (z == 1)
		printf("sa\n");
}

void	sb(t_dlist **stackb, int z)
{
	if (!(*stackb) || lstsize(*stackb) < 2)
		return ;
	ft_swap(&((*stackb)->data), &((*stackb)->next->data));
	if (z == 1)
		printf("sb\n");
}

void	ss(t_dlist **stacka, t_dlist **stackb)
{
	sa(stacka, 0);
	sb(stackb, 0);
	printf("ss\n");
}
