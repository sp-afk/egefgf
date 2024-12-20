/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dilemmeII.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:05:10 by mdoumane          #+#    #+#             */
/*   Updated: 2024/11/27 19:05:10 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psutiles.h"

void	pa(t_dlist **stackb, t_dlist **stacka, int z)
{
	t_dlist	*push;

	push = get_head(*stackb);
	if (!(*stackb))
		return ;
	put_head(stacka, push -> data);
	del_head(stackb);
	if (z == 1)
		printf("pa\n");
}

void	pb(t_dlist **stacka, t_dlist **stackb, int z)
{
	t_dlist	*push;

	push = get_head(*stacka);
	if (!(*stacka))
		return ;
	put_head(stackb, push -> data);
	del_head(stacka);
	if (z == 1)
		printf("pb\n");
}
