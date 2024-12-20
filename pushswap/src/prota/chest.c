/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:00:36 by mdoumane          #+#    #+#             */
/*   Updated: 2024/12/05 02:15:42 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psutiles.h"

int	check_zeub(char **str, int i)
{
	int	y;

	y = 0;
	while (str[i][y] != 0)
	{
		if ((str[i][y] >= '0' && str[i][y] <= '9') || ((y == 0)
				&& (str[i][y] == '+' || str[i][y] == '-')))
			y++;
		else
			return (1);
	}
	return (0);
}

int	check_twin(char **str, int i)
{
	int	z;

	z = i + 1;
	while (str[z] != 0)
	{
		if (str_cmp(str[i], str[z]) == 0)
			return (1);
		z++;
	}
	return (0);
}

int	cheker(char **str)
{
	int	i;

	i = 1;
	while (str[i] != 0)
	{
		if (check_zeub(str, i) == 1)
			return (1);
		else if (check_twin(str, i) == 1)
			return (1);
		else if ((ft_atoi_long(str[i]) < INT_MIN)
			|| (ft_atoi_long(str[i]) > INT_MAX))
			return (1);
		i++;
	}
	return (0);
}
