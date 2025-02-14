/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:18:10 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/18 15:44:46 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}
/*int	main(void)
{
	int fd = open("test.txt", O_WRONLY | O_CREAT, 0700);
	ft_putchar_fd('a', fd);
	return (0);
}*/
