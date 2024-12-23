/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:16:46 by mdoumane          #+#    #+#             */
/*   Updated: 2024/10/28 20:08:41 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size + 1)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

static int	ft_countdigit(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
	{
		i++;
		n = -147483648;
	}
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*str;
	char	negative;

	negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		negative = 1;
	count = ft_countdigit(n);
	str = ft_strnew(count + negative);
	if (!str)
		return (NULL);
	if (negative)
	{
		n = -n;
		str[0] = '-';
	}
	while (count > 0)
	{
		str[count + negative - 1] = (n % 10) + '0';
		count--;
		n = n / 10;
	}
	return (str);
}
