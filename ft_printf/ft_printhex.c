/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:54:38 by cfleuret          #+#    #+#             */
/*   Updated: 2024/11/07 11:53:43 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putchar(int l, char c)
{
	write(1, &c, 1);
	return (l + 1);
}

int	ft_printhex(char c, int l, unsigned int a)
{
	char	*hexlow;
	char	*hexup;

	hexlow = "0123456789abcdef";
	hexup = "0123456789ABCDEF";
	if (c == 'x')
	{
		if (a >= 16)
			l = ft_printhex(c, l, a / 16);
		ft_putchar(l, hexlow[a % 16]);
	}
	else
	{
		if (a >= 16)
			l = ft_printhex(c, l, a / 16);
		ft_putchar(l, hexup[a % 16]);
	}
	return (l + 1);
}
/*int	main(void)
{
	int l = 0;
	l = ft_printhex('X', l, 200);
	write (1, "\n", 1);
	printf("%X", 200);
	return (0);
}*/
