/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:32:15 by cfleuret          #+#    #+#             */
/*   Updated: 2024/11/07 13:06:05 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdarg.h>

int	ft_printf(const char *f, ...);
int	ft_printchar(int l, char a);
int	ft_printstring(int l, char *a);
int	ft_printint(int l, int a);
int	ft_printhex(char c, int l, unsigned int a);
int	ft_printptr(int t, int l, void *a);
int	ft_printuns(int l, unsigned int a);
#endif
