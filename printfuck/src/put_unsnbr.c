/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:59:55 by mdoumane          #+#    #+#             */
/*   Updated: 2024/10/28 21:29:11 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsnbr(unsigned int n)
{
	int	c;

	c = 0;
	if (n >= 10)
	{
		c += put_unsnbr(n / 10);
		c += put_unsnbr(n % 10);
	}
	else
		c += put_char(n + '0');
	return (c);
}
