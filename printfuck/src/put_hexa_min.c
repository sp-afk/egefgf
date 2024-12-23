/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexa_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:00:15 by mdoumane          #+#    #+#             */
/*   Updated: 2024/10/28 21:29:11 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

int	put_hexa_min(unsigned int n)
{
	int		r;
	char	buffer[100];
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (n == 0)
		c += put_char('0');
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
	while (i > 0)
	{
		i--;
		c += put_char(buffer[i]);
	}
	return (c);
}
