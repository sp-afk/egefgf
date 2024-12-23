/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:00:03 by mdoumane          #+#    #+#             */
/*   Updated: 2024/10/28 21:29:11 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_xohexa(uintptr_t n)
{
	int		r;
	char	buffer[100];
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (n != 0)
	{
		r = n % 16;
		if (r < 10)
			buffer[i] = r + '0';
		else
			buffer[i] = r - 10 + 'a';
		n = n / 16;
		i++;
	}
	c += put_char('0');
	c += put_char('x');
	while (i > 0)
	{
		i--;
		c += put_char(buffer[i]);
	}
	return (c);
}

int	put_pnt(int *pttr)
{
	int			c;
	uintptr_t	r;

	c = 0;
	r = (uintptr_t)pttr;
	if (r == 0)
		c = put_str("(nil)");
	else if (r != 0)
		c = put_xohexa(r);
	return (c);
}
