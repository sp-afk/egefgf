/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:16:46 by mdoumane          #+#    #+#             */
/*   Updated: 2024/10/28 20:08:56 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*duppli;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (s1[size] != '\0')
		size++;
	duppli = (char *)malloc(sizeof(*duppli) * (size + 1));
	if (duppli == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		duppli[i] = s1[i];
		i++;
	}
	duppli[i] = '\0';
	return (duppli);
}
