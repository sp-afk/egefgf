/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:20:26 by mdoumane          #+#    #+#             */
/*   Updated: 2024/12/05 02:15:42 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psutiles.h"

int	allreadyhim(t_dlist *him, int z)
{
	t_dlist	*luckyluck;
	int		b;

	luckyluck = him->next;
	b = 0;
	while (luckyluck != NULL)
	{
		if (him->data < luckyluck->data)
			b++;
		luckyluck = luckyluck->next;
		him = him->next;
	}
	if (b == (z - 1))
		return (1);
	return (0);
}

void	shoescharactere(t_dlist *a, t_dlist *b, int z)
{
	if (z == 1 || allreadyhim(a, z) == 1)
	{
		lst_clear(&a);
		return ;
	}
	if (z == 2)
		altugo(&a);
	else if (z == 3)
		algotr(&a);
	else if (z > 3 && z < 10)
		algo(&a, &b);
	else if (z >= 10)
		algoturk(&a, &b);
	lst_clear(&a);
}

void	pushswap(char **str, int f)
{
	t_dlist	*stack;
	t_dlist	*stbck;
	int		z;
	int		i;

	stack = NULL;
	stbck = NULL;
	z = 0;
	i = 1;
	while (str[i] != 0)
	{
		z = ft_atoi(str[i]);
		put_tail(&stack, z);
		i++;
	}
	if (f == 1 || allreadyhim(stack, f) == 1)
	{
		lst_clear(&stack);
		return ;
	}
	shoescharactere(stack, stbck, f);
}

int	main(int av, char **ac)
{
	int	sr;
	int	z;

	sr = 0;
	z = av - 1;
	if (av)
	{
		sr = cheker(ac);
		if (sr != 0 || av <= 1)
			printf("Error\n");
		//else if (str_cmp(ac[0], "./push_swap") == 0)
			pushswap(ac, z);
		//else if (str_cmp(ac[0], "./checker") == 0)
			//tester(ac, z);
		return (0);
	}
}
