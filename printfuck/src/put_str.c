/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:59:59 by mdoumane          #+#    #+#             */
/*   Updated: 2024/10/28 21:29:11 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

int	put_str(const char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (s == NULL)
		c += put_str("(null)");
	else if (s)
	{
		while (s[i] != '\0')
		{
			c += put_char(s[i]);
			i++;
		}
	}
	return (c);
}
