/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:26:47 by mdoumane          #+#    #+#             */
/*   Updated: 2024/11/02 18:26:47 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# elif BUFFER_SIZE >= 10000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	str_len(const char *s);
char	*str_cpy(char *dst, const char *src);
char	*str_cat(char *dest, const char *src);
char	*get_next_line(int fd);
#endif
