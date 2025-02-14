/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:58:18 by cfleuret          #+#    #+#             */
/*   Updated: 2024/11/07 15:42:05 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printstring(int l, char *a)
{
	int	i;

	if (a == NULL)
	{
		write (1, "(null)", 6);
		return (l + 6);
	}
	i = 0;
	while (a[i])
	{
		write(1, &a[i], 1);
		i++;
	}
	l += i;
	return (l);
}
/*int	main(void)
{
	int l = 0;
	l = ft_printstring(l, "abc");
	printf("%d", l);
	return (0);
}*/
