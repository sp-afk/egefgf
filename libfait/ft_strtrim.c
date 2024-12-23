/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:16:46 by mdoumane          #+#    #+#             */
/*   Updated: 2024/10/28 20:09:06 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*new;
	size_t	start;
	size_t	end;

	if (!s || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (s[start] && ft_isset(s[start], set))
		start++;
	while (end > start && ft_isset(s[end - 1], set))
		end--;
	new = ft_substr(s, start, end - start);
	if (!new)
		return (NULL);
	return (new);
}
