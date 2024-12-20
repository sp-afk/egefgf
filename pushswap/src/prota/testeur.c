/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:45:16 by mdoumane          #+#    #+#             */
/*   Updated: 2024/12/04 18:45:16 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psutiles.h"

void	instru(char *mh, t_dlist **a, t_dlist **b)
{
	if (str_cmp(mh, "rrr\n") == 0)
		rrr(a, b, 0);
	else if (str_cmp(mh, "rr\n") == 0)
		rr(a, b, 0);
	else if (str_cmp(mh, "ss\n") == 0)
		ss(a, b, 0);
	else if (str_cmp(mh, "pb\n") == 0)
		pb(a, b, 0);
	else if (str_cmp(mh, "pa\n") == 0)
		pa(b, a, 0);
	else if (str_cmp(mh, "sb\n") == 0)
		sb(b, 0);
	else if (str_cmp(mh, "sa\n") == 0)
		sa(a, 0);
	else if (str_cmp(mh, "rrb\n") == 0)
		rrb(b, 0);
	else if (str_cmp(mh, "rra\n") == 0)
		rra(a, 0);
	else if (str_cmp(mh, "rb\n") == 0)
		rb(b, 0);
	else if (str_cmp(mh, "ra\n") == 0)
		ra(a, 0);
}

void	so(t_dlist *a, t_dlist *b, int f)
{
	if (b == NULL && allreadyhim(a, f) == 1)
	{
		printf ("OK\n");
		return ;
	}
	else if (b != NULL)
		lst_clear(&b);
	printf("KO\n");
}

void	justdoit(t_dlist *a, t_dlist *b, int f)
{
	char	*mh;

	mh = get_next_line(0);
	while (mh != NULL)
	{
		instru(mh, &a, &b);
		free(mh);
		mh = get_next_line(0);
	}
	so(a, b, f);
	lst_clear(&a);
}

void	tester(char **str, int f)
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
		printf("OK\n");
		lst_clear(&stack);
		return ;
	}
	else
		justdoit(stack, stbck, f);
}
