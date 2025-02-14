/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:13:20 by cfleuret          #+#    #+#             */
/*   Updated: 2024/11/05 17:29:57 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putchar(int l, char c)
{
	write (1, &c, 1);
	return (l + 1);
}

int	ft_printuns(int l, unsigned int a)
{
	if (a >= 10)
		l = ft_printuns(l, a / 10);
	l = ft_putchar(l, a % 10 + '0');
	return (l);
}
/*int	main(void)
{
	int	l = 0;
	l = ft_printuns(l, 4);
	write(1, "\n", 1);
	printf("%d", l);
	return (0);
}*/
