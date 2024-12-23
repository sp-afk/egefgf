/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumane <mdoumane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:32:46 by mdoumane          #+#    #+#             */
/*   Updated: 2024/10/28 21:28:48 by mdoumane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <wchar.h>

// Part 1 - Fonctions Put format
int	put_char(char c);
int	put_hexa_min(unsigned int n);
int	put_hexa(unsigned int n);
int	put_nbr(int n);
int	put_octal(unsigned int n);
int	put_pnt(int *pttr);
int	put_str(const char *s);
int	put_unsnbr(unsigned int n);
int	ft_printf(const char *str, ...);

#endif
