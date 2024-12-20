/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:27:00 by mdoumane          #+#    #+#             */
/*   Updated: 2024/11/02 18:27:00 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	str_len(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*str_cpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	result = s1;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

char	*str_cat(char *dest, const char *src)
{
	int		dest_len;
	int		src_len;
	char	*result;

	if (dest)
		dest_len = str_len(dest);
	else
		dest_len = 0;
	src_len = str_len(src);
	result = malloc(dest_len + src_len + 1);
	if (!result)
		return (NULL);
	if (dest)
		str_cpy(result, dest);
	else
		result[0] = '\0';
	ft_strcat(result, src);
	return (result);
}
