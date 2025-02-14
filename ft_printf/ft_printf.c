/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:24:01 by cfleuret          #+#    #+#             */
/*   Updated: 2024/11/14 14:09:36 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putchar(int l, char c)
{
	write(1, &c, 1);
	return (l + 1);
}

static int	ft_check(char c, int l, va_list a)
{
	int	t;

	t = 0;
	if (c == 'c')
		l = ft_putchar(l, (char)va_arg(a, int));
	if (c == 's')
		l = ft_printstring(l, va_arg(a, char *));
	if (c == 'p')
		l = ft_printptr(t, l, va_arg(a, void *));
	if (c == 'd' || c == 'i')
		l = ft_printint(l, va_arg(a, int));
	if (c == 'u')
		l = ft_printuns(l, va_arg(a, unsigned int));
	if (c == 'x' || c == 'X')
		l = ft_printhex(c, l, va_arg(a, unsigned int));
	if (c == '%')
		l = ft_putchar(l, c);
	return (l);
}

int	ft_printf(const char *f, ...)
{
	va_list	a;
	int		i;
	int		l;

	va_start(a, f);
	if (f == NULL)
		return (0);
	l = 0;
	i = 0;
	while (f[i])
	{
		if (f[i] == '%')
		{
			l = ft_check(f[i + 1], l, a);
			i++;
		}
		else
		{
			ft_putchar(l, f[i]);
			l++;
		}
		i++;
	}
	va_end(a);
	return (l);
}
/*
int	main(void)
{
	char	c = 'c';
	char	*s = "Hello";
	int	*p;
	p = (void *)1;
	int	i = -10;
	unsigned int	u = -1;
	ft_printf("Je veux juste print\n");
	ft_printf("%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%\n", c, s, p, i, i, u, u, u);
	printf("%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%\n", c, s, p, i, i, u, u, u);
	ft_printf("Test de renvoi : %d\n", ft_printf(" NULL %d NULL\n", i));
	printf("Test de renvoi : %d\n", printf(" NULL %d NULL\n", i));
	ft_printf("%c\n", c);
	printf("%c\n", c);
	ft_printf("%s\n", s);
        printf("%s\n", s);
	ft_printf("%p\n", p);
        printf("%p\n", p);
	ft_printf("%d\n", i);
        printf("%d\n", i);
	ft_printf("%i\n", i);
        printf("%i\n", i);
	ft_printf("%u\n", u);
        printf("%u\n", u);
	ft_printf("%X\n", u);
        printf("%X\n", u);
	ft_printf("%x\n", u);
        printf("%x\n", u);
	ft_printf("%%\n");
	printf("%%\n");
}
*/
