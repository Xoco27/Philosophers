/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:55:13 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/18 15:59:36 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	int_min(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (int_min(nb, fd) == 1)
		return ;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}
/*int	main (void)
{
	int fd = open("test.txt", O_WRONLY | O_CREAT, 0700);
	int i = 2147483647;
	ft_putnbr_fd(i, fd);
}*/
