/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:20:26 by mdoumane          #+#    #+#             */
/*   Updated: 2024/12/08 16:17:29 by mdoumane         ###   ########.fr       */
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
	else
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

int	main(int ac, char **av)
{
	int	sr;
	int	z;

	sr = 0;
	z = ac - 1;
	if (ac)
	{
		sr = cheker(av);
		if (sr != 0 /*|| ac <= 1*/)
			printf("Error\n");
		else if (str_cmp(av[0], "./checker") == 0)
			tester(av, z);
		else
			pushswap(av, z);
		return (0);
	}
}
