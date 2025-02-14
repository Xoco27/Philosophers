/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:30:51 by cfleuret          #+#    #+#             */
/*   Updated: 2024/11/07 12:17:30 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printptr(int t, int l, void *a)
{
	char	*hex;

	if (a == (void *)0)
	{
		write(1, "(nil)", 5);
		return (l + 5);
	}
	if (t == 0)
	{
		write (1, "0x", 2);
		l += 2;
		t++;
	}
	hex = "0123456789abcdef";
	if (a >= (void *)16)
		l = ft_printptr(t, l, ((void *)((uintptr_t)a / 16)));
	ft_putchar(hex[(uintptr_t)a % 16]);
	return (l + 1);
}
/*int	main(void)
{
	int	*i;
	i = (void *)10;
	int l = 0;
	ft_printptr(l, i);
	return (0);
}*/
