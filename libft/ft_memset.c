/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:05:20 by cfleuret          #+#    #+#             */
/*   Updated: 2024/11/08 14:01:36 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *p, int c, size_t n)
{
	unsigned char	*b;

	b = p;
	while (n > 0)
	{
		*b = (unsigned char)c;
		b++;
		n--;
	}
	return (p);
}

/*int	main(void)
{
	char str[4] = "abc";
	printf("%s\n", str);
	printf("%p\n", ft_memset(str, 65, sizeof(str)));
	printf("%s\n", str);
	printf("%p\n", ft_memset(str, 66, sizeof(str)));
	printf("%s\n", str);
	return (0);
}*/
