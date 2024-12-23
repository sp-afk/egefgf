/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:27:04 by mdoumane          #+#    #+#             */
/*   Updated: 2024/11/02 18:27:04 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_end(int *i, char **buffer)
{
	int	br;

	br = str_len(*buffer);
	if (*i == -1)
	{
		free(*buffer);
		return (NULL);
	}
	if (*i >= br)
	{
		free(*buffer);
		*buffer = NULL;
		*i = 0;
		br = 0;
	}
	return (*buffer);
}

char	*get_buffer(int fd)
{
	ssize_t	bytes_read;
	int		k;
	char	buff[BUFFER_SIZE + 1];
	char	*z;
	char	*temp;

	k = -1;
	z = NULL;
	bytes_read = 1;
	while ((bytes_read) > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		k += bytes_read;
		if (bytes_read < 0)
			return (NULL);
		buff[bytes_read] = '\0';
		temp = str_cat(z, buff);
		if (z)
			free(z);
		z = temp;
	}
	z = ft_end(&k, &z);
	return (z);
}

int	line_length(char *buffer, int index)
{
	int	i;
	int	br;

	i = index;
	br = str_len(buffer);
	while (i < br && buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	return (i - index);
}

char	*copy_ligne(char *buffer, int *index, int ll)
{
	char	*ligne;
	int		j;

	ligne = (char *)malloc((ll + 2) * sizeof(char));
	if (!ligne)
		return (NULL);
	j = 0;
	while (buffer[*index] != '\n' && buffer[*index] != '\0')
		ligne[j++] = buffer[(*index)++];
	if (buffer[*index] == '\n')
		ligne[j++] = buffer[(*index)++];
	ligne[j] = '\0';
	return (ligne);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	static int	index = 0;
	int			ll;
	char		*ligne;

	if (fd < 0)
	{
		if (buffer != NULL)
			free(buffer);
		buffer = NULL;
		index = 0;
		return (NULL);
	}
	if (buffer == NULL)
	{
		buffer = get_buffer(fd);
		if (!buffer || str_len(buffer) <= 0 || BUFFER_SIZE <= 0)
			return (NULL);
	}
	ll = line_length(buffer, index);
	ligne = copy_ligne(buffer, &index, ll);
	if (!ligne)
		return (NULL);
	ft_end(&index, &buffer);
	return (ligne);
}
