/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_octale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:00:06 by mdoumane          #+#    #+#             */
/*   Updated: 2024/10/28 21:29:11 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_octal(unsigned int n)
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
		if (r >= 0 && r <= 7)
			buffer[i] = r + '0';
		n = n / 16;
		i++;
	}
	while (i >= 0)
	{
		c += put_char(buffer[i]);
		i--;
	}
	return (c);
}
