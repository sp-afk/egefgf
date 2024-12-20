/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:20:26 by mdoumane          #+#    #+#             */
/*   Updated: 2024/11/28 01:20:26 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psutiles.h"

int	cheker(char **str)
{
	int	i;
	int	y;
	int	z;

	i = 1;
	y = 0;
	z = 2;
	while (str[i] != 0)
	{
		y = 0;
		while (str[i][y] != 0)
		{
			if ((str[i][y] >= '0' && str[i][y] <= '9') || ((y == 0) && (str[i][y] == '+' || str[i][y] == '-')))
				y++;
			else
				return (1);
		}
		z = i + 1;
		while (str[z] != 0)
		{
			if (str_cmp (str[i], str[z]) == 0)
				return (1);
			z++;
		}
		if ((ft_atoi_long(str[i]) < INT_MIN) ||(ft_atoi_long(str[i]) > INT_MAX))
			return (1);
		i++;
	}
	return (0);
}

int	allreadyhim(t_dlist *him, int z)
{
	t_dlist *luckyluck = him->next;
	int b = 0;
	while (luckyluck != NULL)
	{
		if(him->data < luckyluck->data)
			b++;
		luckyluck = luckyluck->next;
		him = him->next;
	}
	if (b == (z - 1))
		return (1);
	return (0);
}

void	pushswap(char **str, int f)
{
	t_dlist *stack = NULL;
	t_dlist *stbck = NULL;

	int z = 0;
	int i = 1;

	while (str[i] != 0)
	{
		z = ft_atoi(str[i]);
		put_tail(&stack, z);
		i++;
	}
	if (f == 1 || allreadyhim(stack, f) == 1)
	{
		lst_clear(&stack);
		return;
	}
	if (f == 2)
		altugo(&stack);
	else if (f == 3)
		algotr(&stack);
	else if(f > 3 && f < 10)
		algo(&stack, &stbck);
	else
		algoturk(&stack, &stbck);
	lst_clear(&stack);
}

int main (int av, char **ac)
{
	int sr = 0;
	int z = av - 1;

	if (av)
	{
		sr = cheker(ac);
		if (sr != 0 || av <= 1)
			printf("Error\n");
		else
			pushswap(ac, z);
	return (0);
	}
}

