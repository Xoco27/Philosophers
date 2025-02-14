/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:12:45 by cfleuret          #+#    #+#             */
/*   Updated: 2024/11/07 10:59:09 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putchar(int l, char c)
{
	write (1, &c, 1);
	return (l + 1);
}

static int	ft_putnbr(int l, int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (l + 11);
	}
	if (nb < 0)
	{
		l = ft_putchar (l, '-');
		nb *= -1;
	}
	if (nb >= 10)
		l = ft_putnbr(l, nb / 10);
	l = ft_putchar(l, nb % 10 + '0');
	return (l);
}

int	ft_printint(int l, int a)
{
	l = ft_putnbr(l, a);
	return (l);
}
/*int	main(void)
{
	int	l = 0;
	l = ft_printint('i', l, -2147483645);
	write(1, "\n", 1);
	printf("%d", l);
	return (0);
}*/
