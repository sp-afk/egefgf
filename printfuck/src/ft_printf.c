/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:19:51 by mdoumane          #+#    #+#             */
/*   Updated: 2024/10/28 21:29:11 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(va_list args, const char f)
{
	int	l;

	l = 0;
	if (f == 'c' || f == 'C')
		l += put_char(va_arg(args, int));
	else if (f == 's' || f == 'S')
		l += put_str(va_arg(args, const char *));
	else if (f == 'p' || f == 'P')
		l += put_pnt(va_arg(args, int *));
	else if (f == 'd' || f == 'i' || f == 'D')
		l += put_nbr(va_arg(args, int));
	else if (f == 'u' || f == 'U')
		l += put_unsnbr(va_arg(args, unsigned int));
	else if (f == 'o' || f == 'O')
		l += put_octal(va_arg(args, unsigned int));
	else if (f == 'X')
		l += put_hexa(va_arg(args, unsigned int));
	else if (f == 'x')
		l += put_hexa_min(va_arg(args, unsigned int));
	else if (f == '%')
		l += put_char('%');
	return (l);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		l;
	va_list	args;

	i = 0;
	l = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			l += format(args, str[i]);
		}
		else
			l += put_char(str[i]);
		i++;
	}
	va_end(args);
	return (l);
}

/*int main(void)
{
	ft_printf("Character: %c, String: %s, Integer: %d\n", 'A', "Hello", 123);
	return 0;
}*/
/*
int d;
	d = 1;
	ft_printf("jecris %d phrase\n", d);
*/
