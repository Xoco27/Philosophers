/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:06:59 by cfleuret          #+#    #+#             */
/*   Updated: 2024/10/15 11:38:27 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*b;

	b = s;
	while (n > 0)
	{
		*b = '\0';
		b++;
		n--;
	}
	return ;
}

/*int 	main(void)
{
	char str[4] = "abc";
	printf("%s\n", str);
	bzero(str, sizeof(str));
	printf("%s\n", str);
	ft_bzero(str, sizeof(str));
	printf("%s\n", str);
	return (0);
}*/
